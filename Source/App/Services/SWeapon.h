#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SWeapon.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USWeapon : public UObject
{
	GENERATED_BODY()

public:
	USWeapon();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSWeapon(const FVector& TargetLocation);
};
