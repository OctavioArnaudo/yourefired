#include "ICoffeePickup.h"

UICoffeePickup::UICoffeePickup()
	: IdentifierName(TEXT("ICoffeePickup")), bIsActive(true)
{
}

bool UICoffeePickup::ProcessICoffeePickup(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UICoffeePickup] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
