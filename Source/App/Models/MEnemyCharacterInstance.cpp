#include "MEnemyCharacterInstance.h"

MEnemyCharacterInstance::MEnemyCharacterInstance()
	: PatrolRadius(500.0f)
	, AggroRange(800.0f)
	, MeleeAttackRange(150.0f)
	, EnemyProjectileClass(nullptr)
	, PatrolHomeLocation(FVector::ZeroVector)
	, bIsChasingPlayer(false)
	, Health(80.0f)
	, ShootModel(nullptr)
{
}

UMShoot* MEnemyCharacterInstance::GetShootModel()
{
	if (!ShootModel)
	{
		ShootModel = NewObject<UMShoot>();
		if (ShootModel)
		{
			ShootModel->FireRate = 1.5f;
		}
	}
	return ShootModel;
}
