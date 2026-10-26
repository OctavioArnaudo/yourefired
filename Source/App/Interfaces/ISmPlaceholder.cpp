#include "ISmPlaceholder.h"

UISmPlaceholder::UISmPlaceholder()
	: IdentifierName(TEXT("ISmPlaceholder")), bIsActive(true)
{
}

bool UISmPlaceholder::ProcessISmPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UISmPlaceholder] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
