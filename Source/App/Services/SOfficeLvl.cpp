#include "SOfficeLvl.h"

USOfficeLvl::USOfficeLvl()
	: IdentifierName(TEXT("SOfficeLvl")), bIsActive(true)
{
}

bool USOfficeLvl::ProcessSOfficeLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USOfficeLvl] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
