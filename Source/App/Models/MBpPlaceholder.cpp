#include "MBpPlaceholder.h"

UMBpPlaceholder::UMBpPlaceholder()
	: IdentifierName(TEXT("MBpPlaceholder")), bIsActive(true)
{
}

bool UMBpPlaceholder::ProcessMBpPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMBpPlaceholder] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
