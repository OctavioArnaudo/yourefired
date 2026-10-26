#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VWeapon.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVWeapon : public UObject
{
	GENERATED_BODY()

public:
	UVWeapon();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVWeapon(const FVector& TargetLocation);
};
