#pragma once

#include "CoreMinimal.h"

namespace App
{
	class APP_API IMovement
	{
	public:
		IMovement();
		virtual ~IMovement() = default;

		virtual void Move(const FVector& Direction, float Speed);
	};
}
