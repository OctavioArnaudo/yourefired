#include "MDynamicPlaceholder.h"

UMDynamicPlaceholder::UMDynamicPlaceholder()
	: IdentifierName(TEXT("MDynamicPlaceholder")), bIsActive(true)
{
}

bool UMDynamicPlaceholder::ProcessMDynamicPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMDynamicPlaceholder] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
