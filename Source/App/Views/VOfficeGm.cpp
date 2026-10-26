#include "VOfficeGm.h"

UVOfficeGm::UVOfficeGm()
	: IdentifierName(TEXT("VOfficeGm")), bIsActive(true)
{
}

bool UVOfficeGm::ProcessVOfficeGm(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVOfficeGm] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
