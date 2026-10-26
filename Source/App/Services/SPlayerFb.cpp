#include "SPlayerFb.h"

USPlayerFb::USPlayerFb()
	: IdentifierName(TEXT("SPlayerFb")), bIsActive(true)
{
}

bool USPlayerFb::ProcessSPlayerFb(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USPlayerFb] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
