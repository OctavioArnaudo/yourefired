#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VShoot.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVShoot : public UObject
{
	GENERATED_BODY()

public:
	UVShoot();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVShoot(const FVector& TargetLocation);
};
