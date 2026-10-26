#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VWorldLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVWorldLvl : public UObject
{
	GENERATED_BODY()

public:
	UVWorldLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVWorldLvl(const FVector& TargetLocation);
};
