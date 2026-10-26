#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IWbpHud.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIWbpHud : public UObject
{
	GENERATED_BODY()

public:
	UIWbpHud();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIWbpHud(const FVector& TargetLocation);
};
