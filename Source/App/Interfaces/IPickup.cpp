#include "IPickup.h"

UIPickup::UIPickup()
	: IdentifierName(TEXT("IPickup")), bIsActive(true)
{
}

bool UIPickup::ProcessIPickup(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIPickup] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
