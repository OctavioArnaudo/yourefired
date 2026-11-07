#include "SPatrol.h"
#include "GameFramework/Character.h"

USPatrol::USPatrol()
	: IdentifierName(TEXT("SPatrol")), bIsActive(true)
{
}

bool USPatrol::ProcessSPatrol(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USPatrol] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}

void USPatrol::ExecutePatrolStep(ACharacter* Character, const FVector& HomeLocation, float PatrolRadius)
{
	if (!Character) return;
	UE_LOG(LogTemp, Verbose, TEXT("[USPatrol] Executing unit patrol step for '%s' around Home %s (Radius: %.1f)."),
		*Character->GetName(), *HomeLocation.ToString(), PatrolRadius);
}
