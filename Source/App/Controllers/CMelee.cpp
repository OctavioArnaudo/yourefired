#include "CMelee.h"

UCMelee::UCMelee()
	: IdentifierName(TEXT("CMelee")), bIsActive(true)
{
}

bool UCMelee::ProcessCMelee(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCMelee] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
