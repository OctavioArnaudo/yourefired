#pragma once

#include "CoreMinimal.h"
#include "App/Models/MHealth.h"

class AActor;

class APP_API SHealth
{
public:
	SHealth();

	void ProcessDamage(AActor* Target, MHealth& HealthModel, float Damage);
};
