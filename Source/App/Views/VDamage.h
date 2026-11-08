#pragma once

#include "CoreMinimal.h"

class APP_API VDamage
{
public:
	VDamage();

	void DisplayFloatingDamageNumber(float DamageAmount, const FVector& Location);
};
