#include "SPlayerCharacterInstance.h"
#include "App/Models/MPlayerCharacterInstance.h"
#include "Engine/World.h"

SPlayerCharacterInstance::SPlayerCharacterInstance()
{
	ShootService = NewObject<USShoot>();
	MeleeService = NewObject<USMelee>();
}

void SPlayerCharacterInstance::HandleMovement(ACharacter* Character, float Value, bool bForward)
{
	Movement.ApplyMovement(Character, Value, bForward);
}

void SPlayerCharacterInstance::HandleSprint(ACharacter* Character, MPlayerCharacterInstance& Model, bool bStart)
{
	Sprint.SetSprintState(Character, Model.Sprint, Model.Movement, bStart);
}

void SPlayerCharacterInstance::RotateTowardsCursor(ACharacter* Character)
{
	Cursor.OrientTowardsCursor(Character);
}

void SPlayerCharacterInstance::PerformMeleeAttack(ACharacter* Character)
{
	if (!MeleeService)
	{
		MeleeService = NewObject<USMelee>();
	}

	if (MeleeService && Character)
	{
		MeleeService->PerformMeleeAttack(Character);
	}
}

void SPlayerCharacterInstance::PerformRangedAttack(ACharacter* Character, MPlayerCharacterInstance& Model, float CurrentTime)
{
	if (!ShootService)
	{
		ShootService = NewObject<USShoot>();
	}

	if (ShootService && Model.GetShootModel())
	{
		ShootService->PerformDiscreteRangedShoot(Character, Model.GetShootModel(), Model.ProjectileClass, CurrentTime);
	}
}
