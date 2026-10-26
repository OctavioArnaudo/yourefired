#include "CCoffeePickup.h"

UCCoffeePickup::UCCoffeePickup()
	: IdentifierName(TEXT("CCoffeePickup")), bIsActive(true)
{
}

bool UCCoffeePickup::ProcessCCoffeePickup(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCCoffeePickup] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
