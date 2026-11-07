#include "CEnemyCharacterInstance.h"
#include "GameFramework/CharacterMovementComponent.h"

ACEnemyCharacterInstance::ACEnemyCharacterInstance()
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
}

void ACEnemyCharacterInstance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	EnemyService.UpdateAIBehavior(this, EnemyModel);
}

void ACEnemyCharacterInstance::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
