#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IPlayerMovement.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIPlayerMovement : public UObject
{
	GENERATED_BODY()

public:
	UIPlayerMovement();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIPlayerMovement(const FVector& TargetLocation);
};
