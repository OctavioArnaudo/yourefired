#include "VMelee.h"

UVMelee::UVMelee()
	: IdentifierName(TEXT("VMelee")), bIsActive(true)
{
}

bool UVMelee::ProcessVMelee(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVMelee] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
