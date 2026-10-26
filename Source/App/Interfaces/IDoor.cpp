#include "IDoor.h"

UIDoor::UIDoor()
	: IdentifierName(TEXT("IDoor")), bIsActive(true)
{
}

bool UIDoor::ProcessIDoor(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIDoor] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
