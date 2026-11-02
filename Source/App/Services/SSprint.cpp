#include "SSprint.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "App/Models/MSprint.h"
#include "App/Models/MMovement.h"

SSprint::SSprint() {}

void SSprint::SetSprintState(ACharacter* Character, MSprint& SprintModel, const MMovement& MovementModel, bool bStart)
{
	SprintModel.bIsSprinting = bStart;
	if (Character && Character->GetCharacterMovement())
	{
		Character->GetCharacterMovement()->MaxWalkSpeed = bStart ? SprintModel.SprintSpeed : MovementModel.WalkSpeed;
	}
}
