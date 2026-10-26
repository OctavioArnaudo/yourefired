#include "CWorldLvl.h"

UCWorldLvl::UCWorldLvl()
	: IdentifierName(TEXT("CWorldLvl")), bIsActive(true)
{
}

bool UCWorldLvl::ProcessCWorldLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCWorldLvl] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
