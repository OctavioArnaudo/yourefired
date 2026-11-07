# ============================================================
# YOU'RE FIRED - Service : Sprint Speed Modifier Service
# ============================================================
import unreal

class SSprintService:
    """Service: Aplicacion de modificador de velocidad de sprint."""

    def apply_sprint_modifier(self, character_actor, sprint_speed=750.0, b_start=True):
        if not character_actor:
            return False
        unreal.log(f"[SSprintService] Aplicando velocidad de sprint {sprint_speed} a {character_actor.get_name()} b_start={b_start}")
        return True
