#pragma once

#include "CoreMinimal.h"

class ACharacter;

namespace App
{
	class APP_API IEnemyCharacterInstance
	{
	public:
		IEnemyCharacterInstance();
		virtual ~IEnemyCharacterInstance() = default;

		virtual void ExecuteBehavior(ACharacter* EnemyCharacter);
	};
}
