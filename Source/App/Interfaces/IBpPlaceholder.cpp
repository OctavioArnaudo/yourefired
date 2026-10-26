#include "IBpPlaceholder.h"

UIBpPlaceholder::UIBpPlaceholder()
	: IdentifierName(TEXT("IBpPlaceholder")), bIsActive(true)
{
}

bool UIBpPlaceholder::ProcessIBpPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIBpPlaceholder] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
