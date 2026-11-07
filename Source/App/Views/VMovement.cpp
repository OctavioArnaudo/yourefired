#include "VMovement.h"

VMovement::VMovement()
{
}

void VMovement::SpawnMovementDust(const FVector& Location)
{
	UE_LOG(LogTemp, Log, TEXT("[VMovement] Spawning movement dust at %s"), *Location.ToString());
}
