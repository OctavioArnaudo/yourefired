#include "MPlayerImc.h"

UMPlayerImc::UMPlayerImc()
	: IdentifierName(TEXT("MPlayerImc")), bIsActive(true)
{
}

bool UMPlayerImc::ProcessMPlayerImc(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMPlayerImc] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
