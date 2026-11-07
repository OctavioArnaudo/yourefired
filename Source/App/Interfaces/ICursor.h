#pragma once

#include "CoreMinimal.h"

namespace App
{
	class APP_API ICursor
	{
	public:
		ICursor();
		virtual ~ICursor() = default;

		virtual FVector GetCursorHitLocation() const;
	};
}
