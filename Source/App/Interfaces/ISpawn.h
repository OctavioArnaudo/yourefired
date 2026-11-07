#pragma once

#include "CoreMinimal.h"

class UWorld;
class AActor;

namespace App
{
	class APP_API ISpawn
	{
	public:
		ISpawn();
		virtual ~ISpawn() = default;

		virtual AActor* RequestSpawn(UWorld* World, UClass* ActorClass, const FTransform& Transform);
	};
}
