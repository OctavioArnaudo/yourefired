#include "ISpawn.h"

namespace App
{
	ISpawn::ISpawn()
	{
	}

	AActor* ISpawn::RequestSpawn(UWorld* World, UClass* ActorClass, const FTransform& Transform)
	{
		UE_LOG(LogTemp, Log, TEXT("[ISpawn] RequestSpawn default interface contract called."));
		return nullptr;
	}
}
