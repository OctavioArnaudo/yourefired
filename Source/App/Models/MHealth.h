#pragma once
#include "CoreMinimal.h"

class APP_API MHealth
{
public:
	MHealth();
	MHealth(float InMaxHealth);

	float MaxHealth;
	float CurrentHealth;
	bool bIsDead;

	float GetHealth() const { return CurrentHealth; }
	float GetMaxHealth() const { return MaxHealth; }
	float GetHealthPercent() const { return MaxHealth > 0.0f ? (CurrentHealth / MaxHealth) : 0.0f; }
	bool IsDead() const { return bIsDead; }

	float TakeDamage(float Amount)
	{
		if (bIsDead) return CurrentHealth;
		float Dmg = FMath::Max(0.0f, Amount);
		CurrentHealth = FMath::Max(0.0f, CurrentHealth - Dmg);
		if (CurrentHealth <= 0.0f) bIsDead = true;
		return CurrentHealth;
	}

	float Heal(float Amount)
	{
		float H = FMath::Max(0.0f, Amount);
		CurrentHealth = FMath::Min(MaxHealth, CurrentHealth + H);
		if (CurrentHealth > 0.0f) bIsDead = false;
		return CurrentHealth;
	}
};
