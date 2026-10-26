#include "MAiPatrol.h"

UMAiPatrol::UMAiPatrol()
	: IdentifierName(TEXT("MAiPatrol")), bIsActive(true)
{
}

bool UMAiPatrol::ProcessMAiPatrol(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMAiPatrol] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
