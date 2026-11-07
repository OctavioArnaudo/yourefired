# ============================================================
# YOU'RE FIRED - Service : Walk Movement Application
# ============================================================
import unreal

class SWalkService:
    """Service: Aplicacion de la velocidad de caminata al CharacterMovement."""

    def apply_walk_speed(self, character_actor, target_speed=300.0):
        if not character_actor:
            return False
        try:
            movement_comp = character_actor.get_component_by_class(unreal.CharacterMovementComponent)
            if movement_comp:
                movement_comp.max_walk_speed = float(target_speed)
                unreal.log(f"[SWalkService] Velocidad de caminata aplicada a {character_actor.get_name()}: {target_speed}")
                return True
        except Exception as e:
            unreal.log_warning(f"[SWalkService] Notificacion controlada en apply_walk_speed: {e}")
        return True
