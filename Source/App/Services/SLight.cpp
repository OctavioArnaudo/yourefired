#include "SLight.h"

USLight::USLight()
	: IdentifierName(TEXT("SLight")), bIsActive(true)
{
}

bool USLight::ProcessSLight(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USLight] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
