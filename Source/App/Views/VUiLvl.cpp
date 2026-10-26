#include "VUiLvl.h"

UVUiLvl::UVUiLvl()
	: IdentifierName(TEXT("VUiLvl")), bIsActive(true)
{
}

bool UVUiLvl::ProcessVUiLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVUiLvl] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
