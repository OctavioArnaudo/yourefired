#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ILvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UILvl : public UObject
{
	GENERATED_BODY()

public:
	UILvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessILvl(const FVector& TargetLocation);
};
