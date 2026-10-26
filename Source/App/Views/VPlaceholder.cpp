#include "VPlaceholder.h"

UVPlaceholder::UVPlaceholder()
	: IdentifierName(TEXT("VPlaceholder")), bIsActive(true)
{
}

bool UVPlaceholder::ProcessVPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVPlaceholder] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
