#include "SGameLvl.h"

USGameLvl::USGameLvl()
	: IdentifierName(TEXT("SGameLvl")), bIsActive(true)
{
}

bool USGameLvl::ProcessSGameLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USGameLvl] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
