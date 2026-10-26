#include "ICamera.h"

UICamera::UICamera()
	: IdentifierName(TEXT("ICamera")), bIsActive(true)
{
}

bool UICamera::ProcessICamera(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UICamera] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
