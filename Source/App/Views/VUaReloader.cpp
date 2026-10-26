#include "VUaReloader.h"

UVUaReloader::UVUaReloader()
	: IdentifierName(TEXT("VUaReloader")), bIsActive(true)
{
}

bool UVUaReloader::ProcessVUaReloader(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVUaReloader] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
