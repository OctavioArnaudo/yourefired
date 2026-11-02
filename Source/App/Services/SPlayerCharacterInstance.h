#pragma once

#include "CoreMinimal.h"
#include "SMovement.h"
#include "SHealth.h"
#include "SSprint.h"
#include "SWalk.h"
#include "SRange.h"
#include "SProjectile.h"
#include "SSpawn.h"
#include "SCamera.h"
#include "SCursor.h"

class ACharacter;
class MPlayerCharacterInstance;

class APP_API SPlayerCharacterInstance
{
public:
	SPlayerCharacterInstance();

	void HandleMovement(ACharacter* Character, float Value, bool bForward);
	void HandleSprint(ACharacter* Character, MPlayerCharacterInstance& Model, bool bStart);
	void RotateTowardsCursor(ACharacter* Character);
	void PerformMeleeAttack();
	void PerformRangedAttack(ACharacter* Character, const MPlayerCharacterInstance& Model);

	SMovement Movement;
	SHealth Health;
	SSprint Sprint;
	SWalk Walk;
	SRange Range;
	SProjectile Projectile;
	SSpawn Spawn;
	SCamera Camera;
	SCursor Cursor;
};
