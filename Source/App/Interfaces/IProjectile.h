#pragma once

#include "CoreMinimal.h"

class AActor;

namespace App
{
	class APP_API IProjectile
	{
	public:
		IProjectile();
		virtual ~IProjectile() = default;

		virtual void OnImpact(AActor* HitActor, const FVector& ImpactPoint);
	};
}
