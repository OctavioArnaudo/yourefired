#include "CFbPlaceholder.h"

UCFbPlaceholder::UCFbPlaceholder()
	: IdentifierName(TEXT("CFbPlaceholder")), bIsActive(true)
{
}

bool UCFbPlaceholder::ProcessCFbPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCFbPlaceholder] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
