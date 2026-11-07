#include "ICursor.h"

namespace App
{
	ICursor::ICursor()
	{
	}

	FVector ICursor::GetCursorHitLocation() const
	{
		return FVector::ZeroVector;
	}
}
