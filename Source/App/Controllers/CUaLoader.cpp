#include "CUaLoader.h"

UCUaLoader::UCUaLoader()
	: IdentifierName(TEXT("CUaLoader")), bIsActive(true)
{
}

bool UCUaLoader::ProcessCUaLoader(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCUaLoader] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
