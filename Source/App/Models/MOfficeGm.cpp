#include "MOfficeGM.h"

UMOfficeGM::UMOfficeGM()
	: IdentifierName(TEXT("MOfficeGM")), bIsActive(true)
{
}

bool UMOfficeGM::ProcessMOfficeGM(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMOfficeGM] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
