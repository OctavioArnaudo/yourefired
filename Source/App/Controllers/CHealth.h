#pragma once

#include "CoreMinimal.h"
#include "App/Models/MHealth.h"

class APP_API CHealth
{
public:
	CHealth();

	bool ReceiveDamage(MHealth& HealthModel, float DamageAmount);
	bool RestoreHealth(MHealth& HealthModel, float HealAmount);
};
