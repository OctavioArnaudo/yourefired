#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SEnvironment.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USEnvironment : public UObject
{
	GENERATED_BODY()

public:
	USEnvironment();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSEnvironment(const FVector& TargetLocation);
};
