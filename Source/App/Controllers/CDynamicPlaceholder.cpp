#include "CDynamicPlaceholder.h"

UCDynamicPlaceholder::UCDynamicPlaceholder()
	: IdentifierName(TEXT("CDynamicPlaceholder")), bIsActive(true)
{
}

bool UCDynamicPlaceholder::ProcessCDynamicPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCDynamicPlaceholder] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
