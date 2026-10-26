#include "SMPlaceholder.h"

USMPlaceholder::USMPlaceholder()
	: IdentifierName(TEXT("SMPlaceholder")), bIsActive(true)
{
}

bool USMPlaceholder::ProcessSMPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USMPlaceholder] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
