#include "CPlayerActor.h"

UCPlayerActor::UCPlayerActor()
	: IdentifierName(TEXT("CPlayerActor")), bIsActive(true)
{
}

bool UCPlayerActor::ProcessCPlayerActor(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCPlayerActor] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
