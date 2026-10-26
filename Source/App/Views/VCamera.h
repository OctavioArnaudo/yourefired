#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VCamera.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVCamera : public UObject
{
	GENERATED_BODY()

public:
	UVCamera();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVCamera(const FVector& TargetLocation);
};
