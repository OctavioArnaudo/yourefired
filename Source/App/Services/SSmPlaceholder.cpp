#include "SSmPlaceholder.h"

USSmPlaceholder::USSmPlaceholder()
	: IdentifierName(TEXT("SSmPlaceholder")), bIsActive(true)
{
}

bool USSmPlaceholder::ProcessSSmPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USSmPlaceholder] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
