#include "CRange.h"
#include "GameFramework/Actor.h"

CRange::CRange()
{
}

bool CRange::IsInRange(AActor* Origin, AActor* Target, const MRange& RangeModel)
{
	if (!Origin || !Target) return false;
	float Dist = FVector::Dist(Origin->GetActorLocation(), Target->GetActorLocation());
	return Dist <= RangeModel.RangedSpawnOffset;
}
