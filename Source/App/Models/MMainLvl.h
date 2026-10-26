#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MMainLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMMainLvl : public UObject
{
	GENERATED_BODY()

public:
	UMMainLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMMainLvl(const FVector& TargetLocation);
};
