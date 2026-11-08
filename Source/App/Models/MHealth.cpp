#include "MHealth.h"

MHealth::MHealth()
	: MaxHealth(100.0f)
	, CurrentHealth(100.0f)
	, bIsDead(false)
{
}

MHealth::MHealth(float InMaxHealth)
	: MaxHealth(FMath::Max(1.0f, InMaxHealth))
	, CurrentHealth(FMath::Max(1.0f, InMaxHealth))
	, bIsDead(false)
{
}
