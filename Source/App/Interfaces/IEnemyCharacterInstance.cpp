#include "IEnemyCharacterInstance.h"
#include "GameFramework/Character.h"

namespace App
{
	IEnemyCharacterInstance::IEnemyCharacterInstance()
	{
	}

	void IEnemyCharacterInstance::ExecuteBehavior(ACharacter* EnemyCharacter)
	{
		if (EnemyCharacter)
		{
			UE_LOG(LogTemp, Log, TEXT("[IEnemyCharacterInstance] Executing behavior for %s"), *EnemyCharacter->GetName());
		}
	}
}
