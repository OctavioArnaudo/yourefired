#include "VSmPlaceholder.h"

UVSmPlaceholder::UVSmPlaceholder()
	: IdentifierName(TEXT("VSmPlaceholder")), bIsActive(true)
{
}

bool UVSmPlaceholder::ProcessVSmPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVSmPlaceholder] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
