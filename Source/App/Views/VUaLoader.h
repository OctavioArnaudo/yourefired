#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VUaLoader.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVUaLoader : public UObject
{
	GENERATED_BODY()

public:
	UVUaLoader();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVUaLoader(const FVector& TargetLocation);
};
