#include "CPlayerFb.h"

UCPlayerFb::UCPlayerFb()
	: IdentifierName(TEXT("CPlayerFb")), bIsActive(true)
{
}

bool UCPlayerFb::ProcessCPlayerFb(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCPlayerFb] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
