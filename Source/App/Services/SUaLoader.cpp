#include "SUaLoader.h"

USUaLoader::USUaLoader()
	: IdentifierName(TEXT("SUaLoader")), bIsActive(true)
{
}

bool USUaLoader::ProcessSUaLoader(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USUaLoader] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
