# ============================================================
# YOU'RE FIRED - Model : PlayerFb
# ============================================================
import unreal

class MPlayerFbData:
    """Model: Definición de datos, parámetros y estado para PlayerFb."""
    def __init__(self, value=100.0, is_active=True):
        self.domain_name = "player_fb"
        self.value = value
        self.is_active = is_active
        self.config_path = "/Game/YoureFired/Data/DT_PlayerFb"

    def get_summary(self):
        return f"PlayerFb State -> Active: {self.is_active}, Value: {self.value}"
