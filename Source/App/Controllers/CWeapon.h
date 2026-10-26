#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CWeapon.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCWeapon : public UObject
{
	GENERATED_BODY()

public:
	UCWeapon();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCWeapon(const FVector& TargetLocation);
};
