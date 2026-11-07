#pragma once
#include "CoreMinimal.h"

class APP_API MEnemyCharacterInstance
{
public:
	MEnemyCharacterInstance();

	float PatrolRadius;
	float AggroRange;
	float MeleeAttackRange;
	TSubclassOf<AActor> EnemyProjectileClass;
	FVector PatrolHomeLocation;
	bool bIsChasingPlayer;
};
