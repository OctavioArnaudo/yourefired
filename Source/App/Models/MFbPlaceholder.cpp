#include "MFbPlaceholder.h"

UMFbPlaceholder::UMFbPlaceholder()
	: IdentifierName(TEXT("MFbPlaceholder")), bIsActive(true)
{
}

bool UMFbPlaceholder::ProcessMFbPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMFbPlaceholder] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
