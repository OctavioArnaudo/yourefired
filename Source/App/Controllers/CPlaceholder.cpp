#include "CPlaceholder.h"

UCPlaceholder::UCPlaceholder()
	: IdentifierName(TEXT("CPlaceholder")), bIsActive(true)
{
}

bool UCPlaceholder::ProcessCPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCPlaceholder] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
