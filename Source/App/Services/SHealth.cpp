#include "SHealth.h"
#include "GameFramework/Actor.h"

SHealth::SHealth()
{
}

void SHealth::ProcessDamage(AActor* Target, MHealth& HealthModel, float Damage)
{
	if (!Target) return;

	HealthModel.CurrentHealth = FMath::Max(0.0f, HealthModel.CurrentHealth - Damage);
	UE_LOG(LogTemp, Log, TEXT("[SHealth] Processed %.2f damage to %s. New HP: %.2f"), Damage, *Target->GetName(), HealthModel.CurrentHealth);
}
