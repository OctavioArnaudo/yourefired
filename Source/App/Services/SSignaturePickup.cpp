#include "SSignaturePickup.h"

USSignaturePickup::USSignaturePickup()
	: IdentifierName(TEXT("SSignaturePickup")), bIsActive(true)
{
}

bool USSignaturePickup::ProcessSSignaturePickup(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USSignaturePickup] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
