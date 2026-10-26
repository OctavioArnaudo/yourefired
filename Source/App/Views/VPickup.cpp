#include "VPickup.h"

UVPickup::UVPickup()
	: IdentifierName(TEXT("VPickup")), bIsActive(true)
{
}

bool UVPickup::ProcessVPickup(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVPickup] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
