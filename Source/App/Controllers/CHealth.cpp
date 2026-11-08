#include "CHealth.h"

CHealth::CHealth()
{
}

float CHealth::GetCurrentHealth(const MHealth& HealthModel) const
{
	return HealthModel.GetHealth();
}

float CHealth::GetMaxHealth(const MHealth& HealthModel) const
{
	return HealthModel.GetMaxHealth();
}

float CHealth::GetHealthPercent(const MHealth& HealthModel) const
{
	return HealthModel.GetHealthPercent();
}

bool CHealth::IsDead(const MHealth& HealthModel) const
{
	return HealthModel.IsDead();
}

bool CHealth::ReceiveDamage(MHealth& HealthModel, float DamageAmount)
{
	HealthModel.TakeDamage(DamageAmount);
	return !HealthModel.IsDead();
}

bool CHealth::RestoreHealth(MHealth& HealthModel, float HealAmount)
{
	HealthModel.Heal(HealAmount);
	return true;
}
