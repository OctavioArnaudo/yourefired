#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MDefeatLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMDefeatLvl : public UObject
{
	GENERATED_BODY()

public:
	UMDefeatLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMDefeatLvl(const FVector& TargetLocation);
};
