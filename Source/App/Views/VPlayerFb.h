#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VPlayerFb.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVPlayerFb : public UObject
{
	GENERATED_BODY()

public:
	UVPlayerFb();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVPlayerFb(const FVector& TargetLocation);
};
