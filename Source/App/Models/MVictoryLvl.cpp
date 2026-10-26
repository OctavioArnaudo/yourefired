#include "MVictoryLvl.h"

UMVictoryLvl::UMVictoryLvl()
	: IdentifierName(TEXT("MVictoryLvl")), bIsActive(true)
{
}

bool UMVictoryLvl::ProcessMVictoryLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMVictoryLvl] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
