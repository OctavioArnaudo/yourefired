#include "CUaNormalizer.h"

UCUaNormalizer::UCUaNormalizer()
	: IdentifierName(TEXT("CUaNormalizer")), bIsActive(true)
{
}

bool UCUaNormalizer::ProcessCUaNormalizer(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCUaNormalizer] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
