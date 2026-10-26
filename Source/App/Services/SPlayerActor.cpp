#include "SPlayerActor.h"

USPlayerActor::USPlayerActor()
	: IdentifierName(TEXT("SPlayerActor")), bIsActive(true)
{
}

bool USPlayerActor::ProcessSPlayerActor(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USPlayerActor] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
