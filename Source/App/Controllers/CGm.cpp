#include "CGm.h"

UCGm::UCGm()
	: IdentifierName(TEXT("CGm")), bIsActive(true)
{
}

bool UCGm::ProcessCGm(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCGm] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
