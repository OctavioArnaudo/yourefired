#include "MOfficeLvl.h"

UMOfficeLvl::UMOfficeLvl()
	: IdentifierName(TEXT("MOfficeLvl")), bIsActive(true)
{
}

bool UMOfficeLvl::ProcessMOfficeLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMOfficeLvl] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
