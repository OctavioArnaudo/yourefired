#include "IProjectile.h"
#include "GameFramework/Actor.h"

namespace App
{
	IProjectile::IProjectile()
	{
	}

	void IProjectile::OnImpact(AActor* HitActor, const FVector& ImpactPoint)
	{
		UE_LOG(LogTemp, Log, TEXT("[IProjectile] OnImpact contract triggered at %s"), *ImpactPoint.ToString());
	}
}
