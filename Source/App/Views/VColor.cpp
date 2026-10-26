#include "VColor.h"

UVColor::UVColor()
	: IdentifierName(TEXT("VColor")), bIsActive(true)
{
}

bool UVColor::ProcessVColor(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVColor] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
