#pragma once

#include "CoreMinimal.h"

namespace App
{
	class APP_API IPickupActorInstance
	{
	public:
		IPickupActorInstance();
		virtual ~IPickupActorInstance() = default;

		virtual void OnCollected(class ACharacter* Collector);
	};
}
