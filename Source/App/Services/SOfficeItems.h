#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SOfficeItems.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USOfficeItems : public UObject
{
	GENERATED_BODY()

public:
	USOfficeItems();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSOfficeItems(const FVector& TargetLocation);
};
