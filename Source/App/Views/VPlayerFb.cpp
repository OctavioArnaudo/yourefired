#include "VPlayerFb.h"

UVPlayerFb::UVPlayerFb()
	: IdentifierName(TEXT("VPlayerFb")), bIsActive(true)
{
}

bool UVPlayerFb::ProcessVPlayerFb(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVPlayerFb] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
