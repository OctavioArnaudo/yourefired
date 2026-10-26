#include "MLvl.h"

UMLvl::UMLvl()
	: IdentifierName(TEXT("MLvl")), bIsActive(true)
{
}

bool UMLvl::ProcessMLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMLvl] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
