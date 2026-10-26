#include "IVictoryLvl.h"

UIVictoryLvl::UIVictoryLvl()
	: IdentifierName(TEXT("IVictoryLvl")), bIsActive(true)
{
}

bool UIVictoryLvl::ProcessIVictoryLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIVictoryLvl] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
