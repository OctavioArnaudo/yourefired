#include "IPlayerCharacterInstance.h"
#include "GameFramework/Character.h"

namespace App
{
	IPlayerCharacterInstance::IPlayerCharacterInstance()
	{
	}

	void IPlayerCharacterInstance::HandlePlayerInput(ACharacter* PlayerCharacter)
	{
		if (PlayerCharacter)
		{
			UE_LOG(LogTemp, Log, TEXT("[IPlayerCharacterInstance] Handling player input for %s"), *PlayerCharacter->GetName());
		}
	}
}
