#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MCamera.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMCamera : public UObject
{
	GENERATED_BODY()

public:
	UMCamera();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMCamera(const FVector& TargetLocation);
};
