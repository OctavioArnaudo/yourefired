#pragma once
#include "CoreMinimal.h"

class ACharacter;
class MEnemyCharacterInstance;

class APP_API SEnemyCharacterInstance
{
public:
	SEnemyCharacterInstance();
	void UpdateAIBehavior(ACharacter* EnemyCharacter, MEnemyCharacterInstance& Model);
	void ExecutePatrol(ACharacter* EnemyCharacter, MEnemyCharacterInstance& Model);
	void ExecuteChaseAndAttack(ACharacter* EnemyCharacter, MEnemyCharacterInstance& Model);
	void PerformMeleeAttack();
	void PerformRangedAttack(ACharacter* EnemyCharacter, const MEnemyCharacterInstance& Model);
};
