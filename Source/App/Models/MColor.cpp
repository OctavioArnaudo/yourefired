#include "MColor.h"

UMColor::UMColor()
	: IdentifierName(TEXT("MColor")), bIsActive(true)
{
}

bool UMColor::ProcessMColor(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMColor] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
