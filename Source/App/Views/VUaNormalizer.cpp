#include "VUaNormalizer.h"

UVUaNormalizer::UVUaNormalizer()
	: IdentifierName(TEXT("VUaNormalizer")), bIsActive(true)
{
}

bool UVUaNormalizer::ProcessVUaNormalizer(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVUaNormalizer] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
