#include "HybridPlayerModel.h"
#include "GameFramework/CharacterMovementComponent.h"

AHybridPlayerModel::AHybridPlayerModel()
{
	StressLevel = 0.0f;
	MaxStress = 100.0f;
	WalkSpeed = 300.0f;
	RunSpeed = 600.0f;

	if (GetCharacterMovement())
	{
		GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	}
}
