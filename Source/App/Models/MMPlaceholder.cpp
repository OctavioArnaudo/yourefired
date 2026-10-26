#include "MMPlaceholder.h"

UMMPlaceholder::UMMPlaceholder()
	: IdentifierName(TEXT("MMPlaceholder")), bIsActive(true)
{
}

bool UMMPlaceholder::ProcessMMPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMMPlaceholder] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
