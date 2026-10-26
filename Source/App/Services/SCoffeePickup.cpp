#include "SCoffeePickup.h"

USCoffeePickup::USCoffeePickup()
	: IdentifierName(TEXT("SCoffeePickup")), bIsActive(true)
{
}

bool USCoffeePickup::ProcessSCoffeePickup(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USCoffeePickup] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
