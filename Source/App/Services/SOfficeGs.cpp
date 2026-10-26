#include "SOfficeGs.h"

USOfficeGs::USOfficeGs()
	: IdentifierName(TEXT("SOfficeGs")), bIsActive(true)
{
}

bool USOfficeGs::ProcessSOfficeGs(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USOfficeGs] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
