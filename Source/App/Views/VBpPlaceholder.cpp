#include "VBpPlaceholder.h"

UVBpPlaceholder::UVBpPlaceholder()
	: IdentifierName(TEXT("VBpPlaceholder")), bIsActive(true)
{
}

bool UVBpPlaceholder::ProcessVBpPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVBpPlaceholder] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
