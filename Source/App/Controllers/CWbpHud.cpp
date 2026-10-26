#include "CWbpHud.h"

UCWbpHud::UCWbpHud()
	: IdentifierName(TEXT("CWbpHud")), bIsActive(true)
{
}

bool UCWbpHud::ProcessCWbpHud(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCWbpHud] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
