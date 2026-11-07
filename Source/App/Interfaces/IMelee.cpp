#include "IMelee.h"

UIMelee::UIMelee()
	: IdentifierName(TEXT("IMelee")), bIsActive(true)
{
}

bool UIMelee::ProcessIMelee(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIMelee] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
