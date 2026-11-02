#include "SPlayerCharacterInstance.h"
#include "App/Models/MPlayerCharacterInstance.h"

SPlayerCharacterInstance::SPlayerCharacterInstance()
{
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

void SPlayerCharacterInstance::PerformMeleeAttack()
{
	Range.ExecuteMeleeCheck();
}

void SPlayerCharacterInstance::PerformRangedAttack(ACharacter* Character, const MPlayerCharacterInstance& Model)
{
	Projectile.SpawnProjectile(Character, Model.Projectile, Model.Range);
}
