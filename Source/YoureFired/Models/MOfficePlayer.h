#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "OfficePlayerController.generated.h"

/**
 * Top-down Player Controller for navigating office corridors with mouse cursor aiming.
 */
UCLASS()
class YOUREFIRED_API AOfficePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AOfficePlayerController();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void PrimaryAttack();
	void SecondaryAttack();
	void Interact();
	void UseConsumable();
};
