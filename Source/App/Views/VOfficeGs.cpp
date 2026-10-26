#include "VOfficeGs.h"

UVOfficeGs::UVOfficeGs()
	: IdentifierName(TEXT("VOfficeGs")), bIsActive(true)
{
}

bool UVOfficeGs::ProcessVOfficeGs(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVOfficeGs] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
