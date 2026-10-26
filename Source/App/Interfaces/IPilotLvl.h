#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IPilotLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIPilotLvl : public UObject
{
	GENERATED_BODY()

public:
	UIPilotLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIPilotLvl(const FVector& TargetLocation);
};
