#include "CAiPatrol.h"

UCAiPatrol::UCAiPatrol()
	: IdentifierName(TEXT("CAiPatrol")), bIsActive(true)
{
}

bool UCAiPatrol::ProcessCAiPatrol(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCAiPatrol] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
