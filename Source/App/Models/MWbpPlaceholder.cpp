#include "MWbpPlaceholder.h"

UMWbpPlaceholder::UMWbpPlaceholder()
	: IdentifierName(TEXT("MWbpPlaceholder")), bIsActive(true)
{
}

bool UMWbpPlaceholder::ProcessMWbpPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMWbpPlaceholder] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
