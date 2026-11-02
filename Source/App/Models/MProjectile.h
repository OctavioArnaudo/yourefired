#pragma once
#include "CoreMinimal.h"

class APP_API MProjectile
{
public:
	MProjectile();
	TSubclassOf<AActor> ProjectileClass;
};
