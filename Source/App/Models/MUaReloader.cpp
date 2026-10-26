#include "MUaReloader.h"

UMUaReloader::UMUaReloader()
	: IdentifierName(TEXT("MUaReloader")), bIsActive(true)
{
}

bool UMUaReloader::ProcessMUaReloader(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMUaReloader] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
