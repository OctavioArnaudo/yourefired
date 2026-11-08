#pragma once

#include "CoreMinimal.h"
#include "SMovement.h"
#include "SHealth.h"
#include "SSprint.h"
#include "SWalk.h"
#include "SRange.h"
#include "SMelee.h"
#include "SProjectile.h"
#include "SSpawn.h"
#include "SCamera.h"
#include "SCursor.h"
#include "SShoot.h"

class ACharacter;
class MPlayerCharacterInstance;

class APP_API SPlayerCharacterInstance
{
public:
	SPlayerCharacterInstance();

	void HandleMovement(ACharacter* Character, float Value, bool bForward);
	void HandleSprint(ACharacter* Character, MPlayerCharacterInstance& Model, bool bStart);
	void HandleWalk(ACharacter* Character, MPlayerCharacterInstance& Model, bool bWalk);
	void RotateTowardsCursor(ACharacter* Character);
	void PerformMeleeAttack(ACharacter* Character);
	void PerformRangedAttack(ACharacter* Character, MPlayerCharacterInstance& Model, float CurrentTime);

	USMelee* GetMeleeService();
	USShoot* GetShootService();

	SMovement Movement;
	SHealth Health;
	SSprint Sprint;
	SWalk Walk;
	SRange Range;
	USMelee* MeleeService;
	SProjectile Projectile;
	SSpawn Spawn;
	SCamera Camera;
	SCursor Cursor;
	USShoot* ShootService;
};
