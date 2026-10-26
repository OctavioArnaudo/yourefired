#include "VCoffeePickup.h"

UVCoffeePickup::UVCoffeePickup()
	: IdentifierName(TEXT("VCoffeePickup")), bIsActive(true)
{
}

bool UVCoffeePickup::ProcessVCoffeePickup(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVCoffeePickup] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
