#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VMainLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVMainLvl : public UObject
{
	GENERATED_BODY()

public:
	UVMainLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVMainLvl(const FVector& TargetLocation);
};
