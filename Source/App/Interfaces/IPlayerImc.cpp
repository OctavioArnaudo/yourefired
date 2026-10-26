#include "IPlayerImc.h"

UIPlayerImc::UIPlayerImc()
	: IdentifierName(TEXT("IPlayerImc")), bIsActive(true)
{
}

bool UIPlayerImc::ProcessIPlayerImc(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIPlayerImc] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
