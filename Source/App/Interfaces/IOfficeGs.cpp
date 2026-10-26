#include "IOfficeGs.h"

UIOfficeGs::UIOfficeGs()
	: IdentifierName(TEXT("IOfficeGs")), bIsActive(true)
{
}

bool UIOfficeGs::ProcessIOfficeGs(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIOfficeGs] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
