#include "IUaLoader.h"

UIUaLoader::UIUaLoader()
	: IdentifierName(TEXT("IUaLoader")), bIsActive(true)
{
}

bool UIUaLoader::ProcessIUaLoader(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIUaLoader] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
