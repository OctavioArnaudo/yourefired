#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WorkerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStressChanged, float, CurrentStress, float, MaxStress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCoffeeCountChanged, int32, CoffeeCount);

/**
 * Player Character - An overworked employee navigating the office ladder to ask for a raise.
 */
UCLASS()
class YOUREFIRED_API AWorkerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AWorkerCharacter();

protected:
	virtual void BeginPlay() override;

	/** Top-Down Camera Components */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* TopDownCameraComponent;

public:
	virtual void Tick(float DeltaTime) override;

	/** Stress / Health System */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Worker | Stress")
	float CurrentStress;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Worker | Stress")
	float MaxStress;

	/** Inventory / Consumables */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Worker | Inventory")
	int32 CoffeeCount;

	/** Delegates */
	UPROPERTY(BlueprintAssignable, Category = "Worker | Events")
	FOnStressChanged OnStressChanged;

	UPROPERTY(BlueprintAssignable, Category = "Worker | Events")
	FOnCoffeeCountChanged OnCoffeeCountChanged;

	/** Modify Stress level */
	UFUNCTION(BlueprintCallable, Category = "Worker | Stress")
	void AddStress(float Amount);

	UFUNCTION(BlueprintCallable, Category = "Worker | Stress")
	void ReduceStress(float Amount);

	/** Add Coffee to inventory */
	UFUNCTION(BlueprintCallable, Category = "Worker | Inventory")
	void AddCoffee(int32 Amount = 1);

	/** Actions */
	UFUNCTION(BlueprintCallable, Category = "Worker | Actions")
	void PrimaryAttack();

	UFUNCTION(BlueprintCallable, Category = "Worker | Actions")
	void SecondaryAttack();

	UFUNCTION(BlueprintCallable, Category = "Worker | Actions")
	void Interact();

	UFUNCTION(BlueprintCallable, Category = "Worker | Actions")
	void UseConsumable();
};
