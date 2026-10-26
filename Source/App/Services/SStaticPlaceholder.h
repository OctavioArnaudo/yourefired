#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SStaticPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USStaticPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	USStaticPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSStaticPlaceholder(const FVector& TargetLocation);
};
