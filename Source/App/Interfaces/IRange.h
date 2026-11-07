#pragma once

#include "CoreMinimal.h"

class AActor;

namespace App
{
	class APP_API IRange
	{
	public:
		IRange();
		virtual ~IRange() = default;

		virtual bool CheckCombatRange(AActor* Target, float MaxDistance);
	};
}
