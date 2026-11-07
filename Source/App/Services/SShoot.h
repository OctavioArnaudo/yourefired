#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "App/Models/MShoot.h"
#include "SShoot.generated.h"

class ACharacter;

UCLASS(BlueprintType, Blueprintable)
class APP_API USShoot : public UObject
{
	GENERATED_BODY()

public:
	USShoot();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSShoot(const FVector& TargetLocation);

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool PerformRangedShoot(ACharacter* Shooter, TSubclassOf<AActor> ProjectileClass);

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool PerformDiscreteRangedShoot(ACharacter* Shooter, UMShoot* ShootModel, TSubclassOf<AActor> ProjectileClass, float CurrentTime);
};
