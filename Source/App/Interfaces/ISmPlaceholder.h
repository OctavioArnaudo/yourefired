#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ISmPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UISmPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UISmPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessISmPlaceholder(const FVector& TargetLocation);
};
