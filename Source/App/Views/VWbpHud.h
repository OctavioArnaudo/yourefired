#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VWbpHud.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVWbpHud : public UObject
{
	GENERATED_BODY()

public:
	UVWbpHud();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVWbpHud(const FVector& TargetLocation);
};
