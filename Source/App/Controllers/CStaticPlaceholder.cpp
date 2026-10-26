#include "CStaticPlaceholder.h"

UCStaticPlaceholder::UCStaticPlaceholder()
	: IdentifierName(TEXT("CStaticPlaceholder")), bIsActive(true)
{
}

bool UCStaticPlaceholder::ProcessCStaticPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCStaticPlaceholder] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
