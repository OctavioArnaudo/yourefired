#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VPlayerActor.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVPlayerActor : public UObject
{
	GENERATED_BODY()

public:
	UVPlayerActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVPlayerActor(const FVector& TargetLocation);
};
