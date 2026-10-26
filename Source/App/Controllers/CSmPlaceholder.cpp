#include "CSmPlaceholder.h"

UCSmPlaceholder::UCSmPlaceholder()
	: IdentifierName(TEXT("CSmPlaceholder")), bIsActive(true)
{
}

bool UCSmPlaceholder::ProcessCSmPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCSmPlaceholder] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
