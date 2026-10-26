#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MWeapon.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMWeapon : public UObject
{
	GENERATED_BODY()

public:
	UMWeapon();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMWeapon(const FVector& TargetLocation);
};
