#include "VPlayerImc.h"

UVPlayerImc::UVPlayerImc()
	: IdentifierName(TEXT("VPlayerImc")), bIsActive(true)
{
}

bool UVPlayerImc::ProcessVPlayerImc(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVPlayerImc] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
