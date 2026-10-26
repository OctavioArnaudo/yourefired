#include "COfficeItems.h"

UCOfficeItems::UCOfficeItems()
	: IdentifierName(TEXT("COfficeItems")), bIsActive(true)
{
}

bool UCOfficeItems::ProcessCOfficeItems(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCOfficeItems] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
