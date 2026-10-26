#include "CMainLvl.h"

UCMainLvl::UCMainLvl()
	: IdentifierName(TEXT("CMainLvl")), bIsActive(true)
{
}

bool UCMainLvl::ProcessCMainLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCMainLvl] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
