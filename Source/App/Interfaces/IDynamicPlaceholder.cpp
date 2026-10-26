#include "IDynamicPlaceholder.h"

UIDynamicPlaceholder::UIDynamicPlaceholder()
	: IdentifierName(TEXT("IDynamicPlaceholder")), bIsActive(true)
{
}

bool UIDynamicPlaceholder::ProcessIDynamicPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIDynamicPlaceholder] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
