#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IPlayerFb.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIPlayerFb : public UObject
{
	GENERATED_BODY()

public:
	UIPlayerFb();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIPlayerFb(const FVector& TargetLocation);
};
