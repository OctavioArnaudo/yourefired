#include "MGameLvl.h"

UMGameLvl::UMGameLvl()
	: IdentifierName(TEXT("MGameLvl")), bIsActive(true)
{
}

bool UMGameLvl::ProcessMGameLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMGameLvl] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
