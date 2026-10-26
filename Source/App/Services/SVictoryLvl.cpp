#include "SVictoryLvl.h"

USVictoryLvl::USVictoryLvl()
	: IdentifierName(TEXT("SVictoryLvl")), bIsActive(true)
{
}

bool USVictoryLvl::ProcessSVictoryLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USVictoryLvl] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
