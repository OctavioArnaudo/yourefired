# ============================================================
# YOU'RE FIRED - Model : GameLvl
# ============================================================
import unreal

class MGameLvlData:
    """Model: Definición de datos, parámetros y estado para GameLvl."""
    def __init__(self, value=100.0, is_active=True):
        self.domain_name = "game_lvl"
        self.value = value
        self.is_active = is_active
        self.config_path = "/Game/YoureFired/Data/DT_GameLvl"

    def get_summary(self):
        return f"GameLvl State -> Active: {self.is_active}, Value: {self.value}"
