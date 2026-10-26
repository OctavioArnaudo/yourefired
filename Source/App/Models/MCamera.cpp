#include "MCamera.h"

UMCamera::UMCamera()
	: IdentifierName(TEXT("MCamera")), bIsActive(true)
{
}

bool UMCamera::ProcessMCamera(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMCamera] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
