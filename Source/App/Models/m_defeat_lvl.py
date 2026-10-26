# ============================================================
# YOU'RE FIRED - Model : DefeatLvl
# ============================================================
import unreal

class MDefeatLvlModel:
    """Model: Datos y estado de DefeatLvl."""
    def __init__(self, value=100.0, enabled=True):
        self.value = value
        self.enabled = enabled
        self.name = "DefeatLvl"
