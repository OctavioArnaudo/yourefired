#include "VMainLvl.h"

UVMainLvl::UVMainLvl()
	: IdentifierName(TEXT("VMainLvl")), bIsActive(true)
{
}

bool UVMainLvl::ProcessVMainLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVMainLvl] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
