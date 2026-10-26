#include "ILight.h"

UILight::UILight()
	: IdentifierName(TEXT("ILight")), bIsActive(true)
{
}

bool UILight::ProcessILight(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UILight] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
