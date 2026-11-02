#include "CPlayerCharacterInstance.h"
#include "GameFramework/CharacterMovementComponent.h"

ACPlayerCharacterInstance::ACPlayerCharacterInstance()
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
}

void ACPlayerCharacterInstance::BeginPlay()
{
	Super::BeginPlay();
}

void ACPlayerCharacterInstance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	PlayerService.RotateTowardsCursor(this);
}

void ACPlayerCharacterInstance::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACPlayerCharacterInstance::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACPlayerCharacterInstance::MoveRight);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ACPlayerCharacterInstance::StartSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ACPlayerCharacterInstance::StopSprint);

	PlayerInputComponent->BindAction("MeleeAttack", IE_Pressed, this, &ACPlayerCharacterInstance::PerformMeleeAttack);
	PlayerInputComponent->BindAction("RangedAttack", IE_Pressed, this, &ACPlayerCharacterInstance::PerformRangedAttack);
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
	PlayerService.PerformMeleeAttack();
}

void ACPlayerCharacterInstance::PerformRangedAttack()
{
	PlayerService.PerformRangedAttack(this, PlayerModel);
}
