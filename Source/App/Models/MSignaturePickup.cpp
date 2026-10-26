#include "MSignaturePickup.h"

UMSignaturePickup::UMSignaturePickup()
	: IdentifierName(TEXT("MSignaturePickup")), bIsActive(true)
{
}

bool UMSignaturePickup::ProcessMSignaturePickup(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMSignaturePickup] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
