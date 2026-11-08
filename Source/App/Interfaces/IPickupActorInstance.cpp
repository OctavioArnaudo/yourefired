#include "IPickupActorInstance.h"

namespace App
{
	IPickupActorInstance::IPickupActorInstance()
	{
	}

	void IPickupActorInstance::OnCollected(ACharacter* Collector)
	{
		UE_LOG(LogTemp, Log, TEXT("[IPickupActorInstance] OnCollected contract called."));
	}
}
