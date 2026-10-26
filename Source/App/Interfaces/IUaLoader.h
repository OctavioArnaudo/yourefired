#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IUaLoader.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIUaLoader : public UObject
{
	GENERATED_BODY()

public:
	UIUaLoader();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIUaLoader(const FVector& TargetLocation);
};
