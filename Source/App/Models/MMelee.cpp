#include "MMelee.h"

UMMelee::UMMelee()
	: IdentifierName(TEXT("MMelee"))
	, bIsActive(true)
	, MeleeDamage(25.0f)
	, MeleeRange(150.0f)
{
}

bool UMMelee::ProcessMMelee(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMMelee] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
