#include "IPlayerFb.h"

UIPlayerFb::UIPlayerFb()
	: IdentifierName(TEXT("IPlayerFb")), bIsActive(true)
{
}

bool UIPlayerFb::ProcessIPlayerFb(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIPlayerFb] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
