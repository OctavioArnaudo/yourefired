#include "VPlayerActor.h"

UVPlayerActor::UVPlayerActor()
	: IdentifierName(TEXT("VPlayerActor")), bIsActive(true)
{
}

bool UVPlayerActor::ProcessVPlayerActor(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVPlayerActor] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
