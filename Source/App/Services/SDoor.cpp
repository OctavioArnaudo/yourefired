#include "SDoor.h"

USDoor::USDoor()
	: IdentifierName(TEXT("SDoor")), bIsActive(true)
{
}

bool USDoor::ProcessSDoor(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USDoor] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
