#include "MSmPlaceholder.h"

UMSmPlaceholder::UMSmPlaceholder()
	: IdentifierName(TEXT("MSmPlaceholder")), bIsActive(true)
{
}

bool UMSmPlaceholder::ProcessMSmPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMSmPlaceholder] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
