# ============================================================
# YOU'RE FIRED - Model : MainLvl
# ============================================================
import unreal

class MMainLvlModel:
    """Model: Datos y estado de MainLvl."""
    def __init__(self, value=100.0, enabled=True):
        self.value = value
        self.enabled = enabled
        self.name = "MainLvl"
