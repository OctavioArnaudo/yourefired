#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VPlayerImc.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVPlayerImc : public UObject
{
	GENERATED_BODY()

public:
	UVPlayerImc();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVPlayerImc(const FVector& TargetLocation);
};
