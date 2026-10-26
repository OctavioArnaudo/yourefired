#include "MPickup.h"

UMPickup::UMPickup()
	: IdentifierName(TEXT("MPickup")), bIsActive(true)
{
}

bool UMPickup::ProcessMPickup(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMPickup] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
