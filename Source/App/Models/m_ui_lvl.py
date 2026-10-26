# ============================================================
# YOU'RE FIRED - Model : UiLvl
# ============================================================
import unreal

class MUiLvlData:
    """Model: Definición de datos, parámetros y estado para UiLvl."""
    def __init__(self, value=100.0, is_active=True):
        self.domain_name = "ui_lvl"
        self.value = value
        self.is_active = is_active
        self.config_path = "/Game/YoureFired/Data/DT_UiLvl"

    def get_summary(self):
        return f"UiLvl State -> Active: {self.is_active}, Value: {self.value}"
