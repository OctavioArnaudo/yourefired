#include "MOfficeItems.h"

UMOfficeItems::UMOfficeItems()
	: IdentifierName(TEXT("MOfficeItems")), bIsActive(true)
{
}

bool UMOfficeItems::ProcessMOfficeItems(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMOfficeItems] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
