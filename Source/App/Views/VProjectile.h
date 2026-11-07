#pragma once

#include "CoreMinimal.h"

class APP_API VProjectile
{
public:
	VProjectile();

	void PlayImpactFX(const FVector& Location);
};
