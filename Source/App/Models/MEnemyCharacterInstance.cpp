#include "MEnemyCharacterInstance.h"

MEnemyCharacterInstance::MEnemyCharacterInstance()
	: PatrolRadius(500.0f)
	, AggroRange(800.0f)
	, MeleeAttackRange(150.0f)
	, EnemyProjectileClass(nullptr)
	, PatrolHomeLocation(FVector::ZeroVector)
	, bIsChasingPlayer(false)
{
}
