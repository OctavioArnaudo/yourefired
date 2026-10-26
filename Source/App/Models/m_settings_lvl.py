# ============================================================
# YOU'RE FIRED - Model : SettingsLvl
# ============================================================
import unreal

class MSettingsLvlModel:
    """Model: Datos y estado de SettingsLvl."""
    def __init__(self, value=100.0, enabled=True):
        self.value = value
        self.enabled = enabled
        self.name = "SettingsLvl"
