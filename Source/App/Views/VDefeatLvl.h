#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VDefeatLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVDefeatLvl : public UObject
{
	GENERATED_BODY()

public:
	UVDefeatLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVDefeatLvl(const FVector& TargetLocation);
};
