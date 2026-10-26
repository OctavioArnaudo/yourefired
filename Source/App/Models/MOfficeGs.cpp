#include "MOfficeGS.h"

UMOfficeGS::UMOfficeGS()
	: IdentifierName(TEXT("MOfficeGS")), bIsActive(true)
{
}

bool UMOfficeGS::ProcessMOfficeGS(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMOfficeGS] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
