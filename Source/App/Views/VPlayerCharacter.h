#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VPlayerCharacter.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVPlayerCharacter : public UObject
{
	GENERATED_BODY()

public:
	UVPlayerCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVPlayerCharacter(const FVector& TargetLocation);
};
