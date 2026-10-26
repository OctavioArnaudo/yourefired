# ============================================================
# YOU'RE FIRED - Model: Unitary Player Movement Data
# ============================================================
import unreal

class MPlayerMovementData:
    """Model: Datos unitarios de velocidad y plano 2D de movimiento del jugador."""
    def __init__(self, walk_speed=300.0, constrain_to_xy=True):
        self.walk_speed = walk_speed
        self.constrain_to_xy = constrain_to_xy
        self.plane_normal = unreal.Vector(0.0, 0.0, 1.0)
