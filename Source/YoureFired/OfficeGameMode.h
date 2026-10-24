#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "OfficeGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameOver);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFloorComplete, int32, ClearedFloor);

/**
 * Main GameMode - Manages level progression and Game Over logic when stress hits maximum.
 */
UCLASS()
class YOUREFIRED_API AOfficeGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AOfficeGameMode();

	virtual void BeginPlay() override;

	/** Triggered when player stress reaches 100% (Game Over: You're Fired!) */
	UFUNCTION(BlueprintCallable, Category = "Game Flow")
	void OnPlayerFired();

	/** Triggered when unlocking and passing through the floor exit door */
	UFUNCTION(BlueprintCallable, Category = "Game Flow")
	void OnFloorCompleted();

	UPROPERTY(BlueprintAssignable, Category = "Game Flow | Events")
	FOnGameOver OnGameOver;

	UPROPERTY(BlueprintAssignable, Category = "Game Flow | Events")
	FOnFloorComplete OnFloorComplete;
};
