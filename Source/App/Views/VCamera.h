#pragma once
#include "CoreMinimal.h"

class ACharacter;
class USpringArmComponent;
class UCameraComponent;

class APP_API VCamera
{
public:
	VCamera();
	void BuildCameraComponents(ACharacter* Owner, USpringArmComponent*& OutBoom, UCameraComponent*& OutCamera);
};
