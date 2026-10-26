#include "SOfficeItems.h"

USOfficeItems::USOfficeItems()
	: IdentifierName(TEXT("SOfficeItems")), bIsActive(true)
{
}

bool USOfficeItems::ProcessSOfficeItems(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USOfficeItems] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
