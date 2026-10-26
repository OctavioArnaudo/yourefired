#include "SDynamicPlaceholder.h"

USDynamicPlaceholder::USDynamicPlaceholder()
	: IdentifierName(TEXT("SDynamicPlaceholder")), bIsActive(true)
{
}

bool USDynamicPlaceholder::ProcessSDynamicPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USDynamicPlaceholder] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
