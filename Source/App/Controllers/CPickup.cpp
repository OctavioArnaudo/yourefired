#include "CPickup.h"

UCPickup::UCPickup()
	: IdentifierName(TEXT("CPickup")), bIsActive(true)
{
}

bool UCPickup::ProcessCPickup(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCPickup] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
