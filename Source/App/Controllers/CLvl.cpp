#include "CLvl.h"

UCLvl::UCLvl()
	: IdentifierName(TEXT("CLvl")), bIsActive(true)
{
}

bool UCLvl::ProcessCLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCLvl] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
