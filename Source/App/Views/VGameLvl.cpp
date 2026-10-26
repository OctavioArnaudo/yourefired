#include "VGameLvl.h"

UVGameLvl::UVGameLvl()
	: IdentifierName(TEXT("VGameLvl")), bIsActive(true)
{
}

bool UVGameLvl::ProcessVGameLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVGameLvl] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
