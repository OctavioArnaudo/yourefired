#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MGameLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMGameLvl : public UObject
{
	GENERATED_BODY()

public:
	UMGameLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMGameLvl(const FVector& TargetLocation);
};
