#include "MUaLoader.h"

UMUaLoader::UMUaLoader()
	: IdentifierName(TEXT("MUaLoader")), bIsActive(true)
{
}

bool UMUaLoader::ProcessMUaLoader(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMUaLoader] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
