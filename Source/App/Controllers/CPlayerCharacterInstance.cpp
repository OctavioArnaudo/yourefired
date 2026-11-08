#include "CPlayerCharacterInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"

ACPlayerCharacterInstance::ACPlayerCharacterInstance()
	: bIsRangedAttacking(false)
{
	PrimaryActorTick.bCanEverTick = true;

	if (GetCharacterMovement())
	{
		GetCharacterMovement()->MaxWalkSpeed = PlayerModel.WalkSpeed;
		GetCharacterMovement()->bOrientRotationToMovement = false;
		GetCharacterMovement()->bConstrainToPlane = true;
		GetCharacterMovement()->SetPlaneConstraintNormal(FVector(0.0f, 0.0f, 1.0f));
	}

	bUseControllerRotationYaw = false;

	PlayerView.SetupVisuals(this, VerticalRectangleMesh, CameraBoom, TopDownCameraComponent);

	ShootController = NewObject<UCShoot>();
}

void ACPlayerCharacterInstance::BeginPlay()
{
	Super::BeginPlay();
}

void ACPlayerCharacterInstance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsDead()) return;

	PlayerService.RotateTowardsCursor(this);
}

void ACPlayerCharacterInstance::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACPlayerCharacterInstance::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACPlayerCharacterInstance::MoveRight);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ACPlayerCharacterInstance::StartSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ACPlayerCharacterInstance::StopSprint);

	PlayerInputComponent->BindAction("Walk", IE_Pressed, this, &ACPlayerCharacterInstance::StartWalk);
	PlayerInputComponent->BindAction("Walk", IE_Released, this, &ACPlayerCharacterInstance::StopWalk);

	PlayerInputComponent->BindAction("MeleeAttack", IE_Pressed, this, &ACPlayerCharacterInstance::PerformMeleeAttack);
	PlayerInputComponent->BindAction("PrimaryAttack", IE_Pressed, this, &ACPlayerCharacterInstance::PerformMeleeAttack);

	PlayerInputComponent->BindAction("RangedAttack", IE_Pressed, this, &ACPlayerCharacterInstance::StartRangedAttack);
	PlayerInputComponent->BindAction("RangedAttack", IE_Released, this, &ACPlayerCharacterInstance::StopRangedAttack);

	PlayerInputComponent->BindAction("SecondaryAttack", IE_Pressed, this, &ACPlayerCharacterInstance::StartRangedAttack);
	PlayerInputComponent->BindAction("SecondaryAttack", IE_Released, this, &ACPlayerCharacterInstance::StopRangedAttack);
}

void ACPlayerCharacterInstance::FireBullet()
{
	if (IsDead() || !GetWorld()) return;
	PlayerService.PerformRangedAttack(this, PlayerModel, GetWorld()->GetTimeSeconds());
}

float ACPlayerCharacterInstance::ReceiveDamageDirect(float Amount)
{
	UE_LOG(LogTemp, Warning, TEXT("[ACPlayerCharacterInstance] RECEIVE DAMAGE DIRECT! Amount=%.2f"), Amount);

	if (IsDead()) return 0.0f;

	float ActualDamage = (Amount > 0.0f) ? Amount : 25.0f;
	HealthController.ReceiveDamage(PlayerModel.Health, ActualDamage);

	UE_LOG(LogTemp, Warning, TEXT("[ACPlayerCharacterInstance] Player took %.2f damage! Current Health: %.2f / %.2f"),
		ActualDamage, GetHealth(), GetMaxHealth());

	if (IsDead())
	{
		UE_LOG(LogTemp, Error, TEXT("[ACPlayerCharacterInstance] PLAYER DIED! Triggering Defeat / Level Restart..."));
		SetActorHiddenInGame(true);
		SetActorEnableCollision(false);
		SetCanBeDamaged(false);
		GetWorld()->GetTimerManager().ClearTimer(FiringTimerHandle);

		if (GetWorld())
		{
			FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(GetWorld());
			UGameplayStatics::OpenLevel(GetWorld(), FName(*CurrentLevelName));
		}
	}

	return ActualDamage;
}

float ACPlayerCharacterInstance::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	return ReceiveDamageDirect(DamageAmount);
}

float ACPlayerCharacterInstance::GetHealth() const
{
	return HealthController.GetCurrentHealth(PlayerModel.Health);
}

float ACPlayerCharacterInstance::GetMaxHealth() const
{
	return HealthController.GetMaxHealth(PlayerModel.Health);
}

float ACPlayerCharacterInstance::GetHealthPercent() const
{
	return HealthController.GetHealthPercent(PlayerModel.Health);
}

bool ACPlayerCharacterInstance::IsDead() const
{
	return HealthController.IsDead(PlayerModel.Health);
}

float ACPlayerCharacterInstance::Heal(float HealAmount)
{
	if (IsDead()) return 0.0f;
	HealthController.RestoreHealth(PlayerModel.Health, HealAmount);
	UE_LOG(LogTemp, Log, TEXT("[ACPlayerCharacterInstance] Player healed by %.2f! Current Health: %.2f / %.2f"),
		HealAmount, GetHealth(), GetMaxHealth());
	return GetHealth();
}

void ACPlayerCharacterInstance::MoveForward(float Value)
{
	if (IsDead()) return;
	PlayerService.HandleMovement(this, Value, true);
}

void ACPlayerCharacterInstance::MoveRight(float Value)
{
	if (IsDead()) return;
	PlayerService.HandleMovement(this, Value, false);
}

void ACPlayerCharacterInstance::StartSprint()
{
	if (IsDead()) return;
	PlayerService.HandleSprint(this, PlayerModel, true);
}

void ACPlayerCharacterInstance::StopSprint()
{
	if (IsDead()) return;
	PlayerService.HandleSprint(this, PlayerModel, false);
}

void ACPlayerCharacterInstance::StartWalk()
{
	if (IsDead()) return;
	PlayerService.HandleWalk(this, PlayerModel, true);
}

void ACPlayerCharacterInstance::StopWalk()
{
	if (IsDead()) return;
	PlayerService.HandleWalk(this, PlayerModel, false);
}

void ACPlayerCharacterInstance::PerformMeleeAttack()
{
	if (IsDead()) return;
	UE_LOG(LogTemp, Warning, TEXT("[ACPlayerCharacterInstance] Melee/Primary Attack action triggered!"));
	PlayerService.PerformMeleeAttack(this);
}

void ACPlayerCharacterInstance::StartRangedAttack()
{
	if (IsDead() || !GetWorld()) return;

	FireBullet();

	float FireRate = PlayerModel.GetShootModel() ? PlayerModel.GetShootModel()->FireRate : 0.25f;
	GetWorld()->GetTimerManager().SetTimer(FiringTimerHandle, this, &ACPlayerCharacterInstance::FireBullet, FireRate, true);
	UE_LOG(LogTemp, Log, TEXT("[ACPlayerCharacterInstance] Start holding ranged attack. Auto-firing enabled at %.2fs rate."), FireRate);
}

void ACPlayerCharacterInstance::StopRangedAttack()
{
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(FiringTimerHandle);
	}
	UE_LOG(LogTemp, Log, TEXT("[ACPlayerCharacterInstance] Stop holding ranged attack. Auto-firing stopped."));
}
