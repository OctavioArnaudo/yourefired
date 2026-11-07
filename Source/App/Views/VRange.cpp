#include "VRange.h"

VRange::VRange()
{
}

void VRange::RenderRangeDebugSphere(const FVector& Location, float Radius)
{
	UE_LOG(LogTemp, Log, TEXT("[VRange] Rendering debug range sphere at %s with radius %.2f"), *Location.ToString(), Radius);
}
