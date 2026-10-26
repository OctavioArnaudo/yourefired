#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IMainLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIMainLvl : public UObject
{
	GENERATED_BODY()

public:
	UIMainLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIMainLvl(const FVector& TargetLocation);
};
