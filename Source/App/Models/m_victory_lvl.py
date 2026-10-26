# ============================================================
# YOU'RE FIRED - Model : VictoryLvl
# ============================================================
import unreal

class MVictoryLvlModel:
    """Model: Datos y estado de VictoryLvl."""
    def __init__(self, value=100.0, enabled=True):
        self.value = value
        self.enabled = enabled
        self.name = "VictoryLvl"
