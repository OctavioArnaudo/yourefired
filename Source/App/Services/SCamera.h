#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SCamera.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USCamera : public UObject
{
	GENERATED_BODY()

public:
	USCamera();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSCamera(const FVector& TargetLocation);
};
