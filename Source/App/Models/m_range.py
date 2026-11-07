# ============================================================
# YOU'RE FIRED - Model : Combat Range Configuration
# ============================================================
import unreal

class MRangeData:
    """Model: Valores de rango cuerpo a cuerpo y a distancia."""

    def __init__(self, melee_range=150.0, ranged_distance=1000.0):
        self.melee_range = float(melee_range)
        self.ranged_distance = float(ranged_distance)
        self.ranged_spawn_offset = 100.0

    def is_within_melee(self, distance):
        return float(distance) <= self.melee_range
