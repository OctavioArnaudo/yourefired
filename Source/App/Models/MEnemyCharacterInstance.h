#pragma once
#include "CoreMinimal.h"
#include "App/Models/MShoot.h"

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

	UPROPERTY()
	UMShoot* ShootModel;
};
