#include "IOfficeLvl.h"

UIOfficeLvl::UIOfficeLvl()
	: IdentifierName(TEXT("IOfficeLvl")), bIsActive(true)
{
}

bool UIOfficeLvl::ProcessIOfficeLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIOfficeLvl] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
