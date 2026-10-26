#include "IPlayerActor.h"

UIPlayerActor::UIPlayerActor()
	: IdentifierName(TEXT("IPlayerActor")), bIsActive(true)
{
}

bool UIPlayerActor::ProcessIPlayerActor(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIPlayerActor] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
