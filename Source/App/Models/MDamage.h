#pragma once

#include "CoreMinimal.h"

class APP_API MDamage
{
public:
	MDamage();

	float BaseDamage;
	float CritMultiplier;
	float ArmorPenetration;

	float CalculateFinalDamage(float IncomingDamage) const;
};
