#include "COfficeLvl.h"

UCOfficeLvl::UCOfficeLvl()
	: IdentifierName(TEXT("COfficeLvl")), bIsActive(true)
{
}

bool UCOfficeLvl::ProcessCOfficeLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCOfficeLvl] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
