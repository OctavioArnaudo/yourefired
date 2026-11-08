#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "App/Models/MPickupActorInstance.h"
#include "CPickupActorInstance.generated.h"

class UStaticMeshComponent;
class UPrimitiveComponent;

UCLASS()
class APP_API ACPickupActorInstance : public AActor
{
	GENERATED_BODY()

public:
	ACPickupActorInstance();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* PickupMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
	float HealAmount;

	UFUNCTION()
	void OnPickupOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	MPickupActorInstance PickupModel;
};
