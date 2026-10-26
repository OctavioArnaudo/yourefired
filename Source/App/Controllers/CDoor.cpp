#include "CDoor.h"

UCDoor::UCDoor()
	: IdentifierName(TEXT("CDoor")), bIsActive(true)
{
}

bool UCDoor::ProcessCDoor(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCDoor] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
