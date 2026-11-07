#pragma once

#include "CoreMinimal.h"

class ACharacter;

namespace App
{
	class APP_API IPlayerCharacterInstance
	{
	public:
		IPlayerCharacterInstance();
		virtual ~IPlayerCharacterInstance() = default;

		virtual void HandlePlayerInput(ACharacter* PlayerCharacter);
	};
}
