#include "CPlayerCharacterInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/World.h"

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
	PlayerService.RotateTowardsCursor(this);

	// Automatic discrete firing when button is held pressed
	if (bIsRangedAttacking && GetWorld())
	{
		PlayerService.PerformRangedAttack(this, PlayerModel, GetWorld()->GetTimeSeconds());
	}
}

void ACPlayerCharacterInstance::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACPlayerCharacterInstance::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACPlayerCharacterInstance::MoveRight);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ACPlayerCharacterInstance::StartSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ACPlayerCharacterInstance::StopSprint);

	PlayerInputComponent->BindAction("MeleeAttack", IE_Pressed, this, &ACPlayerCharacterInstance::PerformMeleeAttack);
	PlayerInputComponent->BindAction("PrimaryAttack", IE_Pressed, this, &ACPlayerCharacterInstance::PerformMeleeAttack);

	// Discrete auto-firing on hold: IE_Pressed starts, IE_Released stops
	PlayerInputComponent->BindAction("RangedAttack", IE_Pressed, this, &ACPlayerCharacterInstance::StartRangedAttack);
	PlayerInputComponent->BindAction("RangedAttack", IE_Released, this, &ACPlayerCharacterInstance::StopRangedAttack);

	PlayerInputComponent->BindAction("SecondaryAttack", IE_Pressed, this, &ACPlayerCharacterInstance::StartRangedAttack);
	PlayerInputComponent->BindAction("SecondaryAttack", IE_Released, this, &ACPlayerCharacterInstance::StopRangedAttack);
}

void ACPlayerCharacterInstance::MoveForward(float Value)
{
	PlayerService.HandleMovement(this, Value, true);
}

void ACPlayerCharacterInstance::MoveRight(float Value)
{
	PlayerService.HandleMovement(this, Value, false);
}

void ACPlayerCharacterInstance::StartSprint()
{
	PlayerService.HandleSprint(this, PlayerModel, true);
}

void ACPlayerCharacterInstance::StopSprint()
{
	PlayerService.HandleSprint(this, PlayerModel, false);
}

void ACPlayerCharacterInstance::PerformMeleeAttack()
{
	UE_LOG(LogTemp, Warning, TEXT("[ACPlayerCharacterInstance] Melee/Primary Attack action triggered!"));
	PlayerService.PerformMeleeAttack();
}

void ACPlayerCharacterInstance::StartRangedAttack()
{
	bIsRangedAttacking = true;
	if (ShootController && PlayerModel.ShootModel)
	{
		ShootController->StartFiring(PlayerModel.ShootModel);
	}
	if (GetWorld())
	{
		PlayerService.PerformRangedAttack(this, PlayerModel, GetWorld()->GetTimeSeconds());
	}
}

void ACPlayerCharacterInstance::StopRangedAttack()
{
	bIsRangedAttacking = false;
	if (ShootController && PlayerModel.ShootModel)
	{
		ShootController->StopFiring(PlayerModel.ShootModel);
	}
}
