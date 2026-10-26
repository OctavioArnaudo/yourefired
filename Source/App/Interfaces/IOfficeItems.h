#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IOfficeItems.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIOfficeItems : public UObject
{
	GENERATED_BODY()

public:
	UIOfficeItems();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIOfficeItems(const FVector& TargetLocation);
};
