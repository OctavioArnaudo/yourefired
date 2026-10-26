#include "VOfficeLvl.h"

UVOfficeLvl::UVOfficeLvl()
	: IdentifierName(TEXT("VOfficeLvl")), bIsActive(true)
{
}

bool UVOfficeLvl::ProcessVOfficeLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVOfficeLvl] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
