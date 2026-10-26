#include "SStaticPlaceholder.h"

USStaticPlaceholder::USStaticPlaceholder()
	: IdentifierName(TEXT("SStaticPlaceholder")), bIsActive(true)
{
}

bool USStaticPlaceholder::ProcessSStaticPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USStaticPlaceholder] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
