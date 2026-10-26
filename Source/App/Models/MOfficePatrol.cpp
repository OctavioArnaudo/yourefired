#include "MOfficePatrol.h"

UMOfficePatrol::UMOfficePatrol()
	: IdentifierName(TEXT("MOfficePatrol")), bIsActive(true)
{
}

bool UMOfficePatrol::ProcessMOfficePatrol(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMOfficePatrol] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
