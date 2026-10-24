#pragma once

#include "CoreMinimal.h"
#include "PickupBase.h"
#include "SignaturePickup.generated.h"

/**
 * Approval Signature Pickup - Increments floor signatures count in GameState.
 */
UCLASS()
class YOUREFIRED_API ASignaturePickup : public APickupBase
{
	GENERATED_BODY()

public:
	ASignaturePickup();

	virtual void OnPickedUp(AActor* PickupInstigator) override;
};
