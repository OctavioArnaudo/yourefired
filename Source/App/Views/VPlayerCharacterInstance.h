#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VMovement.h"
#include "VHealth.h"
#include "VSprint.h"
#include "VWalk.h"
#include "VRange.h"
#include "VProjectile.h"
#include "VSpawn.h"
#include "VCamera.h"
#include "VCursor.h"

class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;

class APP_API VPlayerCharacterInstance
{
public:
	VPlayerCharacterInstance();

	void SetupVisuals(ACharacter* CharacterOwner, UStaticMeshComponent*& OutMesh, USpringArmComponent*& OutBoom, UCameraComponent*& OutCamera);

	VMovement Movement;
	VHealth Health;
	VSprint Sprint;
	VWalk Walk;
	VRange Range;
	VProjectile Projectile;
	VSpawn Spawn;
	VCamera Camera;
	VCursor Cursor;
};
