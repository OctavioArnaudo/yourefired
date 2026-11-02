#pragma once
#include "CoreMinimal.h"

class ACharacter;
class MProjectile;
class MRange;

class APP_API SProjectile
{
public:
	SProjectile();
	void SpawnProjectile(ACharacter* Character, const MProjectile& ProjectileModel, const MRange& RangeModel);
};
