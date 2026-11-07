#include "VProjectile.h"

VProjectile::VProjectile()
{
}

void VProjectile::PlayImpactFX(const FVector& Location)
{
	UE_LOG(LogTemp, Log, TEXT("[VProjectile] Playing projectile impact FX at %s"), *Location.ToString());
}
