#include "IStaticPlaceholder.h"

UIStaticPlaceholder::UIStaticPlaceholder()
	: IdentifierName(TEXT("IStaticPlaceholder")), bIsActive(true)
{
}

bool UIStaticPlaceholder::ProcessIStaticPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIStaticPlaceholder] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
