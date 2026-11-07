#include "MEnemyCharacterInstance.h"

MEnemyCharacterInstance::MEnemyCharacterInstance()
	: PatrolRadius(500.0f)
	, AggroRange(800.0f)
	, MeleeAttackRange(150.0f)
	, EnemyProjectileClass(nullptr)
	, PatrolHomeLocation(FVector::ZeroVector)
	, bIsChasingPlayer(false)
	, ShootModel(nullptr)
{
	ShootModel = NewObject<UMShoot>();
	if (ShootModel)
	{
		ShootModel->FireRate = 0.5f; // Discrete enemy fire rate (1 shot every 0.5 seconds)
	}
}
