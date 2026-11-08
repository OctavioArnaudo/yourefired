#include "MPickupActorInstance.h"

MPickupActorInstance::MPickupActorInstance()
	: HealAmount(25.0f)
	, bIsCollected(false)
{
}

void MPickupActorInstance::SetHealAmount(float Amount)
{
	HealAmount = FMath::Max(0.0f, Amount);
}
