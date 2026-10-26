#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVLvl : public UObject
{
	GENERATED_BODY()

public:
	UVLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVLvl(const FVector& TargetLocation);
};
