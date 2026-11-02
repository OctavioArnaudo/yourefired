#pragma once

#include "CoreMinimal.h"

class ACharacter;
class MPlayerCharacterInstance;

class APP_API SPlayerCharacterInstance
{
public:
	SPlayerCharacterInstance();

	void HandleMovement(ACharacter* Character, float Value, bool bForward);
	void HandleSprint(ACharacter* Character, MPlayerCharacterInstance& Model, bool bStart);
	void RotateTowardsCursor(ACharacter* Character);
	void PerformMeleeAttack();
	void PerformRangedAttack(ACharacter* Character, const MPlayerCharacterInstance& Model);
};
