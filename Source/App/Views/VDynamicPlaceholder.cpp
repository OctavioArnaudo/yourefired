#include "VDynamicPlaceholder.h"

UVDynamicPlaceholder::UVDynamicPlaceholder()
	: IdentifierName(TEXT("VDynamicPlaceholder")), bIsActive(true)
{
}

bool UVDynamicPlaceholder::ProcessVDynamicPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVDynamicPlaceholder] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
