# ============================================================
# YOU'RE FIRED - Service : Movement Execution Service
# ============================================================
import unreal

class SMovementService:
    """Service: Aplicacion de vectores de movimiento a un Character."""

    def execute_movement_step(self, character_actor, direction_vector, scale_value):
        if not character_actor or scale_value == 0.0:
            return False
        unreal.log(f"[SMovementService] Aplicando movimiento a {character_actor.get_name()} dir={direction_vector} escala={scale_value}")
        return True
