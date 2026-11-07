#include "VSprint.cpp"
#include "VSprint.h"

VSprint::VSprint()
{
}

void VSprint::ApplySprintCameraFX(bool bActive)
{
	UE_LOG(LogTemp, Log, TEXT("[VSprint] Sprint camera FOV effect set to: %s"), bActive ? TEXT("Enabled") : TEXT("Disabled"));
}
