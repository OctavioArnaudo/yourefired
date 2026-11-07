#include "CHealth.cpp"
#include "CHealth.h"

CHealth::CHealth()
{
}

bool CHealth::ReceiveDamage(MHealth& HealthModel, float DamageAmount)
{
	HealthModel.CurrentHealth = FMath::Max(0.0f, HealthModel.CurrentHealth - DamageAmount);
	UE_LOG(LogTemp, Log, TEXT("[CHealth] Took damage: %.2f. HP remaining: %.2f"), DamageAmount, HealthModel.CurrentHealth);
	return HealthModel.CurrentHealth > 0.0f;
}

bool CHealth::RestoreHealth(MHealth& HealthModel, float HealAmount)
{
	HealthModel.CurrentHealth = FMath::Min(HealthModel.MaxHealth, HealthModel.CurrentHealth + HealAmount);
	UE_LOG(LogTemp, Log, TEXT("[CHealth] Healed: %.2f. HP now: %.2f"), HealAmount, HealthModel.CurrentHealth);
	return true;
}
