#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IBpPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIBpPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UIBpPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIBpPlaceholder(const FVector& TargetLocation);
};
