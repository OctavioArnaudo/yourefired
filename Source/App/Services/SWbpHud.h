#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SWbpHud.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USWbpHud : public UObject
{
	GENERATED_BODY()

public:
	USWbpHud();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSWbpHud(const FVector& TargetLocation);
};
