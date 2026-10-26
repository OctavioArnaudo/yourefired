#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SLight.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USLight : public UObject
{
	GENERATED_BODY()

public:
	USLight();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSLight(const FVector& TargetLocation);
};
