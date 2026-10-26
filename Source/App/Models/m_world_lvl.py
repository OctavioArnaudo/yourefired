# ============================================================
# YOU'RE FIRED - Model : WorldLvl
# ============================================================
import unreal

class MWorldLvlModel:
    """Model: Datos y estado de WorldLvl."""
    def __init__(self, value=100.0, enabled=True):
        self.value = value
        self.enabled = enabled
        self.name = "WorldLvl"
