#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MPlayerImc.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMPlayerImc : public UObject
{
	GENERATED_BODY()

public:
	UMPlayerImc();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMPlayerImc(const FVector& TargetLocation);
};
