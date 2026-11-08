#include "CDamage.h"

UCDamage::UCDamage()
	: IdentifierName(TEXT("CDamage")), bIsActive(true)
{
}

float UCDamage::ProcessDamageCalculation(float BaseDamage, float CritMultiplier, float RawDamage)
{
	float Dmg = (RawDamage > 0.0f) ? RawDamage : BaseDamage;
	float Calculated = Dmg * CritMultiplier;
	UE_LOG(LogTemp, Log, TEXT("[UCDamage] Processed damage calculation: %.2f"), Calculated);
	return Calculated;
}
