# ============================================================
# YOU'RE FIRED - Model : OfficeLvl
# ============================================================
import unreal

class MOfficeLvlModel:
    """Model: Datos y estado de OfficeLvl."""
    def __init__(self, value=100.0, enabled=True):
        self.value = value
        self.enabled = enabled
        self.name = "OfficeLvl"
