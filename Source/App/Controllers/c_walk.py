# ============================================================
# YOU'RE FIRED - Controller : Walk Input & Control
# ============================================================
import unreal

class CWalkController:
    """Controller: Gestion del evento y velocidad de caminata del personaje."""

    def handle_walk_input(self, walk_model, character_actor, b_start_walk):
        if not walk_model:
            return False
        walk_model.set_walking_state(b_start_walk)
        unreal.log(f"[CWalkController] Procesando entrada de caminata: b_start_walk={b_start_walk}")
        return True
