#include "VDoor.h"

UVDoor::UVDoor()
	: IdentifierName(TEXT("VDoor")), bIsActive(true)
{
}

bool UVDoor::ProcessVDoor(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVDoor] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
