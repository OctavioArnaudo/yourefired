#include "IDamage.h"

namespace App
{
	IDamage::IDamage()
	{
	}

	float IDamage::OnDamageApplied(float DamageAmount)
	{
		UE_LOG(LogTemp, Log, TEXT("[IDamage] Contract OnDamageApplied executed with amount: %.2f"), DamageAmount);
		return DamageAmount;
	}
}
