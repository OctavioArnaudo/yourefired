#include "CUaReloader.h"

UCUaReloader::UCUaReloader()
	: IdentifierName(TEXT("CUaReloader")), bIsActive(true)
{
}

bool UCUaReloader::ProcessCUaReloader(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCUaReloader] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
