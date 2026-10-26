#include "IPlaceholder.h"

UIPlaceholder::UIPlaceholder()
	: IdentifierName(TEXT("IPlaceholder")), bIsActive(true)
{
}

bool UIPlaceholder::ProcessIPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIPlaceholder] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
