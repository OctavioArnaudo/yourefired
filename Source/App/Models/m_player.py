# ============================================================
# YOU'RE FIRED - Model: Player Data Model
# ============================================================
import unreal

class MPlayerModel:
    """Model: Datos y estado del jugador."""
    def __init__(self, health=100.0, stress=0.0):
        self.health = health
        self.stress = stress
