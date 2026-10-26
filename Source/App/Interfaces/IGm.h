#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IGm.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIGm : public UObject
{
	GENERATED_BODY()

public:
	UIGm();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIGm(const FVector& TargetLocation);
};
