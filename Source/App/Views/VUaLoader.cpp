#include "VUaLoader.h"

UVUaLoader::UVUaLoader()
	: IdentifierName(TEXT("VUaLoader")), bIsActive(true)
{
}

bool UVUaLoader::ProcessVUaLoader(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVUaLoader] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
