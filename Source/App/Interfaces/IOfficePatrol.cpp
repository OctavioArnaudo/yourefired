#include "IOfficePatrol.h"

UIOfficePatrol::UIOfficePatrol()
	: IdentifierName(TEXT("IOfficePatrol")), bIsActive(true)
{
}

bool UIOfficePatrol::ProcessIOfficePatrol(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIOfficePatrol] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
