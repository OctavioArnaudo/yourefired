#include "VPatrol.h"

UVPatrol::UVPatrol()
	: IdentifierName(TEXT("VPatrol")), bIsActive(true)
{
}

bool UVPatrol::ProcessVPatrol(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVPatrol] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
