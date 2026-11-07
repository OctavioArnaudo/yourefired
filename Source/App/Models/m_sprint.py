# ============================================================
# YOU'RE FIRED - Model : Sprint State & Multiplier
# ============================================================
import unreal

class MSprintData:
    """Model: Configuracion de velocidad de esprint y estado."""

    def __init__(self, sprint_speed=750.0):
        self.sprint_speed = float(sprint_speed)
        self.b_is_sprinting = False

    def set_sprinting(self, b_sprint):
        self.b_is_sprinting = bool(b_sprint)
        unreal.log(f"[MSprintData] Estado de sprint cambiado a: {self.b_is_sprinting}")
