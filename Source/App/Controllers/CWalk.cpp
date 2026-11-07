#include "CWalk.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

CWalk::CWalk()
{
}

void CWalk::UpdateWalkSpeed(ACharacter* Character, MWalk& WalkModel, float NewSpeed)
{
	WalkModel.SetWalkSpeed(NewSpeed);
	if (Character && Character->GetCharacterMovement())
	{
		Character->GetCharacterMovement()->MaxWalkSpeed = WalkModel.WalkSpeed;
		UE_LOG(LogTemp, Log, TEXT("[CWalk] Updated walk speed for %s to %.2f"), *Character->GetName(), WalkModel.WalkSpeed);
	}
}
