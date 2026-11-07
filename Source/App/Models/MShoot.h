#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MShoot.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMShoot : public UObject
{
	GENERATED_BODY()

public:
	UMShoot();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot")
	bool bIsActive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot")
	bool bIsFiring;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot")
	float ProjectileSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot")
	float FireRate; // Cooldown in seconds between discrete shots (e.g. 0.25s)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot")
	float LastFireTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot")
	TSubclassOf<AActor> ProjectileClass;

	UFUNCTION(BlueprintCallable, Category = "Shoot")
	bool CanFire(float CurrentTime) const;

	UFUNCTION(BlueprintCallable, Category = "Shoot")
	bool ProcessMShoot(const FVector& TargetLocation);
};
