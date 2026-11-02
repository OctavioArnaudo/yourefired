#pragma once

#include "CoreMinimal.h"

class APP_API MPlayerCharacterInstance
{
public:
	MPlayerCharacterInstance();

	float WalkSpeed;
	float SprintSpeed;
	bool bIsSprinting;
	TSubclassOf<AActor> ProjectileClass;
	float RangedSpawnOffset;
};
