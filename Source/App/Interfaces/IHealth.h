#pragma once

#include "CoreMinimal.h"

namespace App
{
	class APP_API IHealth
	{
	public:
		IHealth();
		virtual ~IHealth() = default;

		virtual void OnDamageTaken(float DamageAmount, float RemainingHealth);
	};
}
