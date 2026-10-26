#include "VWbpHud.h"

UVWbpHud::UVWbpHud()
	: IdentifierName(TEXT("VWbpHud")), bIsActive(true)
{
}

bool UVWbpHud::ProcessVWbpHud(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVWbpHud] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
