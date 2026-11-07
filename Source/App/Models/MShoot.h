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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	float ProjectileSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	TSubclassOf<AActor> ProjectileClass;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMShoot(const FVector& TargetLocation);
};
