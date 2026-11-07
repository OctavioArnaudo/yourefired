# ============================================================
# YOU'RE FIRED - Model : Walk State & Parameters
# ============================================================
import unreal

class MWalkData:
    """Model: Parametros de velocidad y estado de caminata."""

    def __init__(self, walk_speed=300.0, acceleration=2048.0):
        self.walk_speed = float(walk_speed)
        self.acceleration = float(acceleration)
        self.b_is_walking = False

    def set_walking_state(self, b_walking):
        self.b_is_walking = bool(b_walking)
        unreal.log(f"[MWalkData] Estado de caminata establecido a: {self.b_is_walking}")
