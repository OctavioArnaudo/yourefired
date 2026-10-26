#include "MDefeatLvl.h"

UMDefeatLvl::UMDefeatLvl()
	: IdentifierName(TEXT("MDefeatLvl")), bIsActive(true)
{
}

bool UMDefeatLvl::ProcessMDefeatLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMDefeatLvl] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
