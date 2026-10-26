#include "SPlaceholder.h"

USPlaceholder::USPlaceholder()
	: IdentifierName(TEXT("SPlaceholder")), bIsActive(true)
{
}

bool USPlaceholder::ProcessSPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USPlaceholder] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
