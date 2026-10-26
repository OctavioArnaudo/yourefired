#include "MUaNormalizer.h"

UMUaNormalizer::UMUaNormalizer()
	: IdentifierName(TEXT("MUaNormalizer")), bIsActive(true)
{
}

bool UMUaNormalizer::ProcessMUaNormalizer(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMUaNormalizer] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
