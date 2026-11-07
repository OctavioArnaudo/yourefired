#include "IHealth.h"

namespace App
{
	IHealth::IHealth()
	{
	}

	void IHealth::OnDamageTaken(float DamageAmount, float RemainingHealth)
	{
		UE_LOG(LogTemp, Log, TEXT("[IHealth] OnDamageTaken contract called: Damage=%.2f, Remaining=%.2f"), DamageAmount, RemainingHealth);
	}
}
