#include "MCoffeePickup.h"

UMCoffeePickup::UMCoffeePickup()
	: IdentifierName(TEXT("MCoffeePickup")), bIsActive(true)
{
}

bool UMCoffeePickup::ProcessMCoffeePickup(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMCoffeePickup] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
