#include "VDamage.h"

VDamage::VDamage()
{
}

void VDamage::DisplayFloatingDamageNumber(float DamageAmount, const FVector& Location)
{
	UE_LOG(LogTemp, Log, TEXT("[VDamage] Displaying floating damage number: %.1f at %s"), DamageAmount, *Location.ToString());
}
