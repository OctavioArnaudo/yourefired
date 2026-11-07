#include "CMovement.h"
#include "GameFramework/Character.h"

CMovement::CMovement()
{
}

void CMovement::HandleMovementInput(ACharacter* Character, float AxisValue, bool bForward)
{
	if (Character && AxisValue != 0.0f)
	{
		FVector Direction = bForward ? FVector(1.0f, 0.0f, 0.0f) : FVector(0.0f, 1.0f, 0.0f);
		Character->AddMovementInput(Direction, AxisValue);
		UE_LOG(LogTemp, Log, TEXT("[CMovement] Added movement input to %s: %.2f"), *Character->GetName(), AxisValue);
	}
}
