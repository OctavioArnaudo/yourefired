#include "SUaReloader.h"

USUaReloader::USUaReloader()
	: IdentifierName(TEXT("SUaReloader")), bIsActive(true)
{
}

bool USUaReloader::ProcessSUaReloader(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USUaReloader] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
