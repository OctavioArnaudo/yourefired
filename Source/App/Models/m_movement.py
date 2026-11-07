# ============================================================
# YOU'RE FIRED - Model : Movement Configuration
# ============================================================
import unreal

class MMovementData:
    """Model: Parametros de velocidad y direccion de movimiento."""

    def __init__(self, walk_speed=400.0):
        self.walk_speed = float(walk_speed)
        self.movement_vector = (0.0, 0.0, 0.0)

    def set_movement_vector(self, x, y, z=0.0):
        self.movement_vector = (float(x), float(y), float(z))
        unreal.log(f"[MMovementData] Vector de movimiento: {self.movement_vector}")
