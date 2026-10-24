#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "OfficeGameState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSignaturesUpdated, int32, CurrentSignatures, int32, RequiredSignatures);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFloorChanged, int32, NewFloor);

/**
 * GameState for the office building - Tracks floor progression and collected approval signatures.
 */
UCLASS()
class YOUREFIRED_API AOfficeGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	AOfficeGameState();

	/** Current office floor (1 = Contabilidad, 2 = Marketing, 3 = RRHH, 4 = Sala de Juntas) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Office | Floor")
	int32 CurrentFloor;

	/** Number of Approval Signatures collected on this floor */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Office | Signatures")
	int32 SignaturesCollected;

	/** Total Approval Signatures required to unlock the floor exit door */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Office | Signatures")
	int32 RequiredSignatures;

	/** Event Delegates */
	UPROPERTY(BlueprintAssignable, Category = "Office | Events")
	FOnSignaturesUpdated OnSignaturesUpdated;

	UPROPERTY(BlueprintAssignable, Category = "Office | Events")
	FOnFloorChanged OnFloorChanged;

	/** Add a signature and notify listeners */
	UFUNCTION(BlueprintCallable, Category = "Office | Signatures")
	void AddSignature();

	/** Check if exit requirements are met */
	UFUNCTION(BlueprintPure, Category = "Office | Signatures")
	bool HasAllSignatures() const;

	/** Advance or set current floor */
	UFUNCTION(BlueprintCallable, Category = "Office | Floor")
	void SetCurrentFloor(int32 NewFloor);
};
