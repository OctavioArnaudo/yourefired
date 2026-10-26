#include "SPickup.h"

USPickup::USPickup()
	: IdentifierName(TEXT("SPickup")), bIsActive(true)
{
}

bool USPickup::ProcessSPickup(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USPickup] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
