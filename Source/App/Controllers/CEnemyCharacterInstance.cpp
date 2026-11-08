#include "CEnemyCharacterInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/World.h"

ACEnemyCharacterInstance::ACEnemyCharacterInstance()
	: EnemyService(nullptr)
{
	PrimaryActorTick.bCanEverTick = true;

	if (GetCharacterMovement())
	{
		GetCharacterMovement()->MaxWalkSpeed = 300.0f;
		GetCharacterMovement()->bOrientRotationToMovement = true;
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 480.0f, 0.0f);
		GetCharacterMovement()->bConstrainToPlane = true;
		GetCharacterMovement()->SetPlaneConstraintNormal(FVector(0.0f, 0.0f, 1.0f));
	}

	bUseControllerRotationYaw = false;

	EnemyView.SetupVisuals(this, VerticalRectangleMesh);
}

void ACEnemyCharacterInstance::BeginPlay()
{
	Super::BeginPlay();
	EnemyModel.PatrolHomeLocation = GetActorLocation();

	if (!EnemyService)
	{
		EnemyService = NewObject<USEnemyCharacterInstance>();
	}
}

void ACEnemyCharacterInstance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsPendingKillPending() || IsDead()) return;

	if (!EnemyService)
	{
		EnemyService = NewObject<USEnemyCharacterInstance>();
	}

	if (EnemyService)
	{
		EnemyService->UpdateAIBehavior(this, EnemyModel);
	}
}

void ACEnemyCharacterInstance::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

float ACEnemyCharacterInstance::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	if (IsDead()) return 0.0f;

	float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	HealthController.ReceiveDamage(EnemyModel.Health, ActualDamage);
	UE_LOG(LogTemp, Warning, TEXT("[ACEnemyCharacterInstance] Enemy %s took %.2f damage! Current HP: %.2f / %.2f"),
		*GetName(), ActualDamage, GetHealth(), GetMaxHealth());

	if (IsDead())
	{
		UE_LOG(LogTemp, Error, TEXT("[ACEnemyCharacterInstance] Enemy %s DIED! Destroying actor..."), *GetName());
		SetActorHiddenInGame(true);
		SetActorEnableCollision(false);
		SetLifeSpan(1.0f); // Destroy actor after 1 second
	}

	return ActualDamage;
}

float ACEnemyCharacterInstance::GetHealth() const
{
	return HealthController.GetCurrentHealth(EnemyModel.Health);
}

float ACEnemyCharacterInstance::GetMaxHealth() const
{
	return HealthController.GetMaxHealth(EnemyModel.Health);
}

float ACEnemyCharacterInstance::GetHealthPercent() const
{
	return HealthController.GetHealthPercent(EnemyModel.Health);
}

bool ACEnemyCharacterInstance::IsDead() const
{
	return HealthController.IsDead(EnemyModel.Health);
}

float ACEnemyCharacterInstance::Heal(float HealAmount)
{
	if (IsDead()) return 0.0f;
	HealthController.RestoreHealth(EnemyModel.Health, HealAmount);
	UE_LOG(LogTemp, Log, TEXT("[ACEnemyCharacterInstance] Enemy %s healed by %.2f! Current HP: %.2f / %.2f"),
		*GetName(), HealAmount, GetHealth(), GetMaxHealth());
	return GetHealth();
}
