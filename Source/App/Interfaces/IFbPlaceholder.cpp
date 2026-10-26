#include "IFbPlaceholder.h"

UIFbPlaceholder::UIFbPlaceholder()
	: IdentifierName(TEXT("IFbPlaceholder")), bIsActive(true)
{
}

bool UIFbPlaceholder::ProcessIFbPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIFbPlaceholder] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
