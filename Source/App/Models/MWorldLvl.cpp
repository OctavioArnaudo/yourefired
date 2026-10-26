#include "MWorldLvl.h"

UMWorldLvl::UMWorldLvl()
	: IdentifierName(TEXT("MWorldLvl")), bIsActive(true)
{
}

bool UMWorldLvl::ProcessMWorldLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMWorldLvl] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
