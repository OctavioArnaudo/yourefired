#include "IUaReloader.h"

UIUaReloader::UIUaReloader()
	: IdentifierName(TEXT("IUaReloader")), bIsActive(true)
{
}

bool UIUaReloader::ProcessIUaReloader(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIUaReloader] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
