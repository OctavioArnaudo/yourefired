#include "CVictoryLvl.h"

UCVictoryLvl::UCVictoryLvl()
	: IdentifierName(TEXT("CVictoryLvl")), bIsActive(true)
{
}

bool UCVictoryLvl::ProcessCVictoryLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCVictoryLvl] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
