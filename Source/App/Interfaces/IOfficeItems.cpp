#include "IOfficeItems.h"

UIOfficeItems::UIOfficeItems()
	: IdentifierName(TEXT("IOfficeItems")), bIsActive(true)
{
}

bool UIOfficeItems::ProcessIOfficeItems(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIOfficeItems] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
