#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MPlayerCharacter.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMPlayerCharacter : public UObject
{
	GENERATED_BODY()

public:
	UMPlayerCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMPlayerCharacter(const FVector& TargetLocation);
};
