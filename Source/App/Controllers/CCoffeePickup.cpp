#include "CoffeePickup.h"
#include "WorkerCharacter.h"

ACoffeePickup::ACoffeePickup()
{
	StressReductionAmount = 25.0f;
}

void ACoffeePickup::OnPickedUp(AActor* PickupInstigator)
{
	AWorkerCharacter* Worker = Cast<AWorkerCharacter>(PickupInstigator);
	if (Worker)
	{
		Worker->AddCoffee(1);
		UE_LOG(LogTemp, Log, TEXT("Coffee picked up! Added to worker inventory."));
		Destroy();
	}
}
