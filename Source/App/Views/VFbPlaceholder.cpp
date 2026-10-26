#include "VFbPlaceholder.h"

UVFbPlaceholder::UVFbPlaceholder()
	: IdentifierName(TEXT("VFbPlaceholder")), bIsActive(true)
{
}

bool UVFbPlaceholder::ProcessVFbPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVFbPlaceholder] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
