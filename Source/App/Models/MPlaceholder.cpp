#include "MPlaceholder.h"

UMPlaceholder::UMPlaceholder()
	: IdentifierName(TEXT("MPlaceholder")), bIsActive(true)
{
}

bool UMPlaceholder::ProcessMPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMPlaceholder] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
