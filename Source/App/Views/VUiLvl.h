#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VUiLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVUiLvl : public UObject
{
	GENERATED_BODY()

public:
	UVUiLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVUiLvl(const FVector& TargetLocation);
};
