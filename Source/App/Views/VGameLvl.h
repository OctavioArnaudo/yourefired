#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VGameLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVGameLvl : public UObject
{
	GENERATED_BODY()

public:
	UVGameLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVGameLvl(const FVector& TargetLocation);
};
