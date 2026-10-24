#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

class UStaticMeshComponent;

UENUM(BlueprintType)
enum class EOfficeWeaponType : uint8
{
	PaperAirplane 	UMETA(DisplayName = "Paper Airplane"),
	Pencil 			UMETA(DisplayName = "Pencil"),
	CoffeeMug 		UMETA(DisplayName = "Coffee Mug"),
	Stapler 		UMETA(DisplayName = "Stapler")
};

/**
 * Office Supply Weapon Base Class
 */
UCLASS()
class YOUREFIRED_API AWeaponBase : public AActor
{
	GENERATED_BODY()

public:
	AWeaponBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon | Components")
	UStaticMeshComponent* MeshComponent;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon | Stats")
	EOfficeWeaponType WeaponType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon | Stats")
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon | Stats")
	int32 Durability;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon | Stats")
	bool bCanBeThrown;

	/** Primary attack with this weapon */
	UFUNCTION(BlueprintCallable, Category = "Weapon | Actions")
	virtual void Attack();

	/** Throw weapon at target */
	UFUNCTION(BlueprintCallable, Category = "Weapon | Actions")
	virtual void ThrowWeapon(FVector Direction);
};
