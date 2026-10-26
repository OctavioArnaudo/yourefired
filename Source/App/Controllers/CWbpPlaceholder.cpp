#include "CWbpPlaceholder.h"

UCWbpPlaceholder::UCWbpPlaceholder()
	: IdentifierName(TEXT("CWbpPlaceholder")), bIsActive(true)
{
}

bool UCWbpPlaceholder::ProcessCWbpPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCWbpPlaceholder] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
