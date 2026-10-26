#include "CMPlaceholder.h"

UCMPlaceholder::UCMPlaceholder()
	: IdentifierName(TEXT("CMPlaceholder")), bIsActive(true)
{
}

bool UCMPlaceholder::ProcessCMPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCMPlaceholder] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
