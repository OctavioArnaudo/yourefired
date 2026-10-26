#include "SWbpHud.h"

USWbpHud::USWbpHud()
	: IdentifierName(TEXT("SWbpHud")), bIsActive(true)
{
}

bool USWbpHud::ProcessSWbpHud(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USWbpHud] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
