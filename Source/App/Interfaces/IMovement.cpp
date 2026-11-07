#include "IMovement.h"

namespace App
{
	IMovement::IMovement()
	{
	}

	void IMovement::Move(const FVector& Direction, float Speed)
	{
		UE_LOG(LogTemp, Log, TEXT("[IMovement] Move contract executed: Dir=%s, Speed=%.2f"), *Direction.ToString(), Speed);
	}
}
