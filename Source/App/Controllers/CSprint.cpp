#include "CSprint.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

CSprint::CSprint()
{
}

void CSprint::ToggleSprint(ACharacter* Character, MSprint& SprintModel, bool bStart)
{
	SprintModel.bIsSprinting = bStart;
	if (Character && Character->GetCharacterMovement())
	{
		Character->GetCharacterMovement()->MaxWalkSpeed = bStart ? SprintModel.SprintSpeed : 400.0f;
		UE_LOG(LogTemp, Log, TEXT("[CSprint] Sprint state set to: %s"), bStart ? TEXT("Active") : TEXT("Inactive"));
	}
}
