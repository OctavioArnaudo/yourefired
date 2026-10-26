#include "CPlayerImc.h"

UCPlayerImc::UCPlayerImc()
	: IdentifierName(TEXT("CPlayerImc")), bIsActive(true)
{
}

bool UCPlayerImc::ProcessCPlayerImc(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCPlayerImc] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
