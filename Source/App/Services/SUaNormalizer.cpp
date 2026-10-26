#include "SUaNormalizer.h"

USUaNormalizer::USUaNormalizer()
	: IdentifierName(TEXT("SUaNormalizer")), bIsActive(true)
{
}

bool USUaNormalizer::ProcessSUaNormalizer(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USUaNormalizer] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
