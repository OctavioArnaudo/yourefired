#pragma once

#include "CoreMinimal.h"
#include "App/Models/MHealth.h"

class APP_API CHealth
{
public:
	CHealth();

	float GetCurrentHealth(const MHealth& HealthModel) const;
	float GetMaxHealth(const MHealth& HealthModel) const;
	float GetHealthPercent(const MHealth& HealthModel) const;
	bool IsDead(const MHealth& HealthModel) const;

	bool ReceiveDamage(MHealth& HealthModel, float DamageAmount);
	bool RestoreHealth(MHealth& HealthModel, float HealAmount);
};
