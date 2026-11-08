#include "SPlayerCharacterInstance.h"
#include "App/Models/MPlayerCharacterInstance.h"
#include "Engine/World.h"

SPlayerCharacterInstance::SPlayerCharacterInstance()
	: MeleeService(nullptr)
	, ShootService(nullptr)
{
}

USMelee* SPlayerCharacterInstance::GetMeleeService()
{
	if (!MeleeService)
	{
		MeleeService = NewObject<USMelee>();
	}
	return MeleeService;
}

USShoot* SPlayerCharacterInstance::GetShootService()
{
	if (!ShootService)
	{
		ShootService = NewObject<USShoot>();
	}
	return ShootService;
}

void SPlayerCharacterInstance::HandleMovement(ACharacter* Character, float Value, bool bForward)
{
	Movement.ApplyMovement(Character, Value, bForward);
}

void SPlayerCharacterInstance::HandleSprint(ACharacter* Character, MPlayerCharacterInstance& Model, bool bStart)
{
	Sprint.SetSprintState(Character, Model.Sprint, Model.Movement, bStart);
}

void SPlayerCharacterInstance::HandleWalk(ACharacter* Character, MPlayerCharacterInstance& Model, bool bWalk)
{
	Model.Walk.bIsWalking = bWalk;
	Walk.ApplyWalkMode(Character, Model.Walk);
}

void SPlayerCharacterInstance::RotateTowardsCursor(ACharacter* Character)
{
	Cursor.OrientTowardsCursor(Character);
}

void SPlayerCharacterInstance::PerformMeleeAttack(ACharacter* Character)
{
	USMelee* Melee = GetMeleeService();
	if (Melee && Character)
	{
		Melee->PerformMeleeAttack(Character);
	}
}

void SPlayerCharacterInstance::PerformRangedAttack(ACharacter* Character, MPlayerCharacterInstance& Model, float CurrentTime)
{
	USShoot* Shoot = GetShootService();
	if (Shoot && Model.GetShootModel())
	{
		Shoot->PerformDiscreteRangedShoot(Character, Model.GetShootModel(), Model.ProjectileClass, CurrentTime);
	}
}
