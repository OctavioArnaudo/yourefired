#include "SBpPlaceholder.h"

USBpPlaceholder::USBpPlaceholder()
	: IdentifierName(TEXT("SBpPlaceholder")), bIsActive(true)
{
}

bool USBpPlaceholder::ProcessSBpPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USBpPlaceholder] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
