#include "COfficePatrol.h"

UCOfficePatrol::UCOfficePatrol()
	: IdentifierName(TEXT("COfficePatrol")), bIsActive(true)
{
}

bool UCOfficePatrol::ProcessCOfficePatrol(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCOfficePatrol] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
