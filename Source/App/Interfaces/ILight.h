#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ILight.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UILight : public UObject
{
	GENERATED_BODY()

public:
	UILight();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessILight(const FVector& TargetLocation);
};
