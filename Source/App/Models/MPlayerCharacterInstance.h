#pragma once

#include "CoreMinimal.h"
#include "MMovement.h"
#include "MHealth.h"
#include "MSprint.h"
#include "MWalk.h"
#include "MRange.h"
#include "MProjectile.h"
#include "MSpawn.h"
#include "MCamera.h"
#include "MCursor.h"
#include "MShoot.h"

class APP_API MPlayerCharacterInstance
{
public:
	MPlayerCharacterInstance();

	float WalkSpeed;
	float SprintSpeed;
	bool bIsSprinting;
	TSubclassOf<AActor> ProjectileClass;
	float RangedSpawnOffset;

	MMovement Movement;
	MHealth Health;
	MSprint Sprint;
	MWalk Walk;
	MRange Range;
	MProjectile Projectile;
	MSpawn Spawn;
	MCamera Camera;
	MCursor Cursor;

	UPROPERTY()
	UMShoot* ShootModel;
};
