#include "MStaticPlaceholder.h"

UMStaticPlaceholder::UMStaticPlaceholder()
	: IdentifierName(TEXT("MStaticPlaceholder")), bIsActive(true)
{
}

bool UMStaticPlaceholder::ProcessMStaticPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMStaticPlaceholder] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
