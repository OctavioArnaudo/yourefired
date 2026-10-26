#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SFbPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USFbPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	USFbPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSFbPlaceholder(const FVector& TargetLocation);
};
