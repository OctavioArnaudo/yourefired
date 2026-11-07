#include "VHealth.h"

VHealth::VHealth()
{
}

void VHealth::RenderHealthUI(float HealthRatio)
{
	UE_LOG(LogTemp, Log, TEXT("[VHealth] Rendering health UI with ratio: %.2f"), HealthRatio);
}
