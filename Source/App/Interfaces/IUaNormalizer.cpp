#include "IUaNormalizer.h"

UIUaNormalizer::UIUaNormalizer()
	: IdentifierName(TEXT("IUaNormalizer")), bIsActive(true)
{
}

bool UIUaNormalizer::ProcessIUaNormalizer(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIUaNormalizer] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
