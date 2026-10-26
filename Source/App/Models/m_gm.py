# ============================================================
# YOU'RE FIRED - Model : Gm
# ============================================================
import unreal

class MGmModel:
    """Model: Datos y estado de Gm."""
    def __init__(self, value=100.0, enabled=True):
        self.value = value
        self.enabled = enabled
        self.name = "Gm"
