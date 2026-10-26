#include "VSignaturePickup.h"

UVSignaturePickup::UVSignaturePickup()
	: IdentifierName(TEXT("VSignaturePickup")), bIsActive(true)
{
}

bool UVSignaturePickup::ProcessVSignaturePickup(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVSignaturePickup] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
