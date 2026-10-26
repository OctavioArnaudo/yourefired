#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IOfficeGm.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIOfficeGm : public UObject
{
	GENERATED_BODY()

public:
	UIOfficeGm();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIOfficeGm(const FVector& TargetLocation);
};
