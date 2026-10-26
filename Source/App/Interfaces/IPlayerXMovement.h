#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IPlayerXMovement.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIPlayerXMovement : public UObject
{
	GENERATED_BODY()

public:
	UIPlayerXMovement();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIPlayerXMovement(const FVector& TargetLocation);
};
