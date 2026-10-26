#include "CUiLvl.h"

UCUiLvl::UCUiLvl()
	: IdentifierName(TEXT("CUiLvl")), bIsActive(true)
{
}

bool UCUiLvl::ProcessCUiLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCUiLvl] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
