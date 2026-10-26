#include "SCamera.h"

USCamera::USCamera()
	: IdentifierName(TEXT("SCamera")), bIsActive(true)
{
}

bool USCamera::ProcessSCamera(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USCamera] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
