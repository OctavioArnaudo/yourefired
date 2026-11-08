#pragma once

#include "CoreMinimal.h"

namespace App
{
	class APP_API IDamage
	{
	public:
		IDamage();
		virtual ~IDamage() = default;

		virtual float OnDamageApplied(float DamageAmount);
	};
}
