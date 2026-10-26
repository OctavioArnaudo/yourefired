#include "SOfficePatrol.h"

USOfficePatrol::USOfficePatrol()
	: IdentifierName(TEXT("SOfficePatrol")), bIsActive(true)
{
}

bool USOfficePatrol::ProcessSOfficePatrol(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USOfficePatrol] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
