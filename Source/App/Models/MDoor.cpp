#include "MDoor.h"

UMDoor::UMDoor()
	: IdentifierName(TEXT("MDoor")), bIsActive(true)
{
}

bool UMDoor::ProcessMDoor(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMDoor] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
