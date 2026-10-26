#include "IMainLvl.h"

UIMainLvl::UIMainLvl()
	: IdentifierName(TEXT("IMainLvl")), bIsActive(true)
{
}

bool UIMainLvl::ProcessIMainLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIMainLvl] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
