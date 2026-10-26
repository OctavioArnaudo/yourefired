#include "VCamera.h"

UVCamera::UVCamera()
	: IdentifierName(TEXT("VCamera")), bIsActive(true)
{
}

bool UVCamera::ProcessVCamera(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVCamera] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
