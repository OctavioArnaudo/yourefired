#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OfficeDoor.generated.h"

class UBoxComponent;
class UStaticMeshComponent;

/**
 * Office Door - Requires all Approval Signatures to unlock and exit to the next floor.
 */
UCLASS()
class YOUREFIRED_API AOfficeDoor : public AActor
{
	GENERATED_BODY()

public:
	AOfficeDoor();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door | Components")
	UBoxComponent* TriggerBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door | Components")
	UStaticMeshComponent* DoorMesh;

	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
	UPROPERTY(BlueprintReadOnly, Category = "Door | State")
	bool bIsUnlocked;

	/** Attempt to open door */
	UFUNCTION(BlueprintCallable, Category = "Door")
	bool TryOpenDoor(AActor* InstigatorActor);
};
