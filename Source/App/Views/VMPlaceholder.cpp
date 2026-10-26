#include "VMPlaceholder.h"

UVMPlaceholder::UVMPlaceholder()
	: IdentifierName(TEXT("VMPlaceholder")), bIsActive(true)
{
}

bool UVMPlaceholder::ProcessVMPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVMPlaceholder] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
