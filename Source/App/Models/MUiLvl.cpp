#include "MUiLvl.h"

UMUiLvl::UMUiLvl()
	: IdentifierName(TEXT("MUiLvl")), bIsActive(true)
{
}

bool UMUiLvl::ProcessMUiLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMUiLvl] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
