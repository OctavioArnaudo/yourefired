# ============================================================
# YOU'RE FIRED - Controller : Sprint Input Controller
# ============================================================
import unreal

class CSprintController:
    """Controller: Gestion de tecla de sprint presionado/soltado."""

    def handle_sprint_toggle(self, sprint_model, b_pressed):
        if not sprint_model:
            return False
        sprint_model.set_sprinting(b_pressed)
        unreal.log(f"[CSprintController] Sprint presionado: {b_pressed}")
        return True
