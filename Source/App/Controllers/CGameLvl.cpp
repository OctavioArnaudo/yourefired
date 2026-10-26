#include "CGameLvl.h"

UCGameLvl::UCGameLvl()
	: IdentifierName(TEXT("CGameLvl")), bIsActive(true)
{
}

bool UCGameLvl::ProcessCGameLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCGameLvl] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
