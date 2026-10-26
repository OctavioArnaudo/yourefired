#include "VVictoryLvl.h"

UVVictoryLvl::UVVictoryLvl()
	: IdentifierName(TEXT("VVictoryLvl")), bIsActive(true)
{
}

bool UVVictoryLvl::ProcessVVictoryLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVVictoryLvl] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
