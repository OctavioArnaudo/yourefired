#include "MWbpHud.h"

UMWbpHud::UMWbpHud()
	: IdentifierName(TEXT("MWbpHud")), bIsActive(true)
{
}

bool UMWbpHud::ProcessMWbpHud(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMWbpHud] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
