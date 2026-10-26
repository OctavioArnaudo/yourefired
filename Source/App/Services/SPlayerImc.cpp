#include "SPlayerImc.h"

USPlayerImc::USPlayerImc()
	: IdentifierName(TEXT("SPlayerImc")), bIsActive(true)
{
}

bool USPlayerImc::ProcessSPlayerImc(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USPlayerImc] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
