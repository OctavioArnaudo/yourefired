#pragma once

#include "CoreMinimal.h"

namespace App
{
	class APP_API IWalk
	{
	public:
		IWalk();
		virtual ~IWalk() = default;

		virtual void OnWalkStateChanged(bool bIsWalking);
	};
}
