#include "VWbpPlaceholder.h"

UVWbpPlaceholder::UVWbpPlaceholder()
	: IdentifierName(TEXT("VWbpPlaceholder")), bIsActive(true)
{
}

bool UVWbpPlaceholder::ProcessVWbpPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVWbpPlaceholder] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
