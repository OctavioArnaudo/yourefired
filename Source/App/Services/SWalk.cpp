#include "SWalk.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "App/Models/MWalk.h"

SWalk::SWalk()
{
}

void SWalk::ApplyWalkMode(ACharacter* Character, const MWalk& WalkModel)
{
	if (Character && Character->GetCharacterMovement())
	{
		Character->GetCharacterMovement()->MaxWalkSpeed = WalkModel.WalkSpeed;
		UE_LOG(LogTemp, Log, TEXT("[SWalk] Walk mode applied with speed: %.2f"), WalkModel.WalkSpeed);
	}
}
