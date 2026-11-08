#include "MDamage.h"

MDamage::MDamage()
	: BaseDamage(25.0f)
	, CritMultiplier(1.5f)
	, ArmorPenetration(0.0f)
{
}

float MDamage::CalculateFinalDamage(float IncomingDamage) const
{
	float Dmg = (IncomingDamage > 0.0f) ? IncomingDamage : BaseDamage;
	return Dmg * CritMultiplier;
}
