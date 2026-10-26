#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ICamera.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UICamera : public UObject
{
	GENERATED_BODY()

public:
	UICamera();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessICamera(const FVector& TargetLocation);
};
