#include "ISignaturePickup.h"

UISignaturePickup::UISignaturePickup()
	: IdentifierName(TEXT("ISignaturePickup")), bIsActive(true)
{
}

bool UISignaturePickup::ProcessISignaturePickup(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UISignaturePickup] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
