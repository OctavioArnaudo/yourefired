#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CCamera.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCCamera : public UObject
{
	GENERATED_BODY()

public:
	UCCamera();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCCamera(const FVector& TargetLocation);
};
