#include "ILvl.h"

UILvl::UILvl()
	: IdentifierName(TEXT("ILvl")), bIsActive(true)
{
}

bool UILvl::ProcessILvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UILvl] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
