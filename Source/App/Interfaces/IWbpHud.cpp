#include "IWbpHud.h"

UIWbpHud::UIWbpHud()
	: IdentifierName(TEXT("IWbpHud")), bIsActive(true)
{
}

bool UIWbpHud::ProcessIWbpHud(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIWbpHud] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
