#pragma once

#include "CoreMinimal.h"

class APP_API MPickupActorInstance
{
public:
	MPickupActorInstance();

	float HealAmount;
	bool bIsCollected;

	void SetHealAmount(float Amount);
};
