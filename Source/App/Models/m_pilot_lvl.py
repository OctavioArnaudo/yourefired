# ============================================================
# YOU'RE FIRED - Model : PilotLvl
# ============================================================
import unreal

class MPilotLvlModel:
    """Model: Datos y estado de PilotLvl."""
    def __init__(self, value=100.0, enabled=True):
        self.value = value
        self.enabled = enabled
        self.name = "PilotLvl"
