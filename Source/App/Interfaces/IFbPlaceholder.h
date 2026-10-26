#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IFbPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIFbPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UIFbPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIFbPlaceholder(const FVector& TargetLocation);
};
