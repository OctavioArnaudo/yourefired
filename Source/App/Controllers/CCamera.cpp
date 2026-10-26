#include "CCamera.h"

UCCamera::UCCamera()
	: IdentifierName(TEXT("CCamera")), bIsActive(true)
{
}

bool UCCamera::ProcessCCamera(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCCamera] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
