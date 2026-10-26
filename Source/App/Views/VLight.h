#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VLight.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVLight : public UObject
{
	GENERATED_BODY()

public:
	UVLight();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVLight(const FVector& TargetLocation);
};
