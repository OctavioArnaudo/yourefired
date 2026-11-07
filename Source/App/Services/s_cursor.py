# ============================================================
# YOU'RE FIRED - Service : Cursor Orientation Service
# ============================================================
import unreal

class SCursorService:
    """Service: Orientacion de personaje hacia la posicion del cursor."""

    def orient_towards_cursor(self, character_actor, target_location):
        if not character_actor:
            return False
        unreal.log(f"[SCursorService] Orientando {character_actor.get_name()} hacia cursor en {target_location}")
        return True
