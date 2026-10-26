#include "SWbpPlaceholder.h"

USWbpPlaceholder::USWbpPlaceholder()
	: IdentifierName(TEXT("SWbpPlaceholder")), bIsActive(true)
{
}

bool USWbpPlaceholder::ProcessSWbpPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USWbpPlaceholder] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
