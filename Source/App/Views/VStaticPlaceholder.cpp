#include "VStaticPlaceholder.h"

UVStaticPlaceholder::UVStaticPlaceholder()
	: IdentifierName(TEXT("VStaticPlaceholder")), bIsActive(true)
{
}

bool UVStaticPlaceholder::ProcessVStaticPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVStaticPlaceholder] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
