#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MPlayerXyzMovement.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMPlayerXyzMovement : public UObject
{
	GENERATED_BODY()

public:
	UMPlayerXyzMovement();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMPlayerXyzMovement(const FVector& TargetLocation);
};
