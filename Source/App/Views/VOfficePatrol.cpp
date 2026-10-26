#include "VOfficePatrol.h"

UVOfficePatrol::UVOfficePatrol()
	: IdentifierName(TEXT("VOfficePatrol")), bIsActive(true)
{
}

bool UVOfficePatrol::ProcessVOfficePatrol(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVOfficePatrol] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
