#include "SFbPlaceholder.h"

USFbPlaceholder::USFbPlaceholder()
	: IdentifierName(TEXT("SFbPlaceholder")), bIsActive(true)
{
}

bool USFbPlaceholder::ProcessSFbPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USFbPlaceholder] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
