#include "CDefeatLvl.h"

UCDefeatLvl::UCDefeatLvl()
	: IdentifierName(TEXT("CDefeatLvl")), bIsActive(true)
{
}

bool UCDefeatLvl::ProcessCDefeatLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCDefeatLvl] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
