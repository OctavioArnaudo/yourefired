#include "VWorldLvl.h"

UVWorldLvl::UVWorldLvl()
	: IdentifierName(TEXT("VWorldLvl")), bIsActive(true)
{
}

bool UVWorldLvl::ProcessVWorldLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVWorldLvl] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
