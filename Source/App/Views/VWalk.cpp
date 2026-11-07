#include "VWalk.h"

VWalk::VWalk()
{
}

void VWalk::PlayFootstepFX(const FVector& Location)
{
	UE_LOG(LogTemp, Log, TEXT("[VWalk] Playing footstep FX at %s"), *Location.ToString());
}
