#include "CSignaturePickup.h"

UCSignaturePickup::UCSignaturePickup()
	: IdentifierName(TEXT("CSignaturePickup")), bIsActive(true)
{
}

bool UCSignaturePickup::ProcessCSignaturePickup(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCSignaturePickup] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
