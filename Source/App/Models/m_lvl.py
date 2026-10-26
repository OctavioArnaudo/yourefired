# ============================================================
# YOU'RE FIRED - Model : Lvl
# ============================================================
import unreal

class MLvlModel:
    """Model: Datos y estado de Lvl."""
    def __init__(self, value=100.0, enabled=True):
        self.value = value
        self.enabled = enabled
        self.name = "Lvl"
