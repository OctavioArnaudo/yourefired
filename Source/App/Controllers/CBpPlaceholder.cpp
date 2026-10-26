#include "CBpPlaceholder.h"

UCBpPlaceholder::UCBpPlaceholder()
	: IdentifierName(TEXT("CBpPlaceholder")), bIsActive(true)
{
}

bool UCBpPlaceholder::ProcessCBpPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCBpPlaceholder] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
