#include "VGm.h"

UVGm::UVGm()
	: IdentifierName(TEXT("VGm")), bIsActive(true)
{
}

bool UVGm::ProcessVGm(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVGm] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
