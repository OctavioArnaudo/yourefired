#include "IGameLvl.h"

UIGameLvl::UIGameLvl()
	: IdentifierName(TEXT("IGameLvl")), bIsActive(true)
{
}

bool UIGameLvl::ProcessIGameLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIGameLvl] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
