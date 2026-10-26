#include "VLvl.h"

UVLvl::UVLvl()
	: IdentifierName(TEXT("VLvl")), bIsActive(true)
{
}

bool UVLvl::ProcessVLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVLvl] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
