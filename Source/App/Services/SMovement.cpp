#include "SMovement.h"
#include "GameFramework/Character.h"
#include "GameFramework/Controller.h"

SMovement::SMovement() {}

void SMovement::ApplyMovement(ACharacter* Character, float Value, bool bForward)
{
	if (Character && Character->GetController() && Value != 0.0f)
	{
		FVector Direction = bForward ? FVector(1.0f, 0.0f, 0.0f) : FVector(0.0f, 1.0f, 0.0f);
		Character->AddMovementInput(Direction, Value);
	}
}
