#include "IWbpPlaceholder.h"

UIWbpPlaceholder::UIWbpPlaceholder()
	: IdentifierName(TEXT("IWbpPlaceholder")), bIsActive(true)
{
}

bool UIWbpPlaceholder::ProcessIWbpPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIWbpPlaceholder] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
