#pragma once

#include "CoreMinimal.h"
#include "PickupBase.h"
#include "CoffeePickup.generated.h"

/**
 * Coffee Pickup - Decreases worker stress or stores coffee in inventory.
 */
UCLASS()
class YOUREFIRED_API ACoffeePickup : public APickupBase
{
	GENERATED_BODY()

public:
	ACoffeePickup();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Coffee")
	float StressReductionAmount;

	virtual void OnPickedUp(AActor* PickupInstigator) override;
};
