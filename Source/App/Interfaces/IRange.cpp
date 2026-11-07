#include "IRange.h"

namespace App
{
	IRange::IRange()
	{
	}

	bool IRange::CheckCombatRange(AActor* Target, float MaxDistance)
	{
		UE_LOG(LogTemp, Log, TEXT("[IRange] CheckCombatRange contract executed."));
		return true;
	}
}
