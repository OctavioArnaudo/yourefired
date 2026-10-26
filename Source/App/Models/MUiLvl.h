#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MUiLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMUiLvl : public UObject
{
	GENERATED_BODY()

public:
	UMUiLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMUiLvl(const FVector& TargetLocation);
};
