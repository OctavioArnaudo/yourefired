#include "MMainLvl.h"

UMMainLvl::UMMainLvl()
	: IdentifierName(TEXT("MMainLvl")), bIsActive(true)
{
}

bool UMMainLvl::ProcessMMainLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMMainLvl] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
