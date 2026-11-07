#include "CPatrol.h"

UCPatrol::UCPatrol()
	: IdentifierName(TEXT("CPatrol")), bIsActive(true)
{
}

bool UCPatrol::ProcessCPatrol(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCPatrol] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
