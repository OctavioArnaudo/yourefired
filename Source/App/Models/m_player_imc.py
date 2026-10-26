# ============================================================
# YOU'RE FIRED - Model : PlayerImc
# ============================================================
import unreal

class MPlayerImcData:
    """Model: Definición de datos, parámetros y estado para PlayerImc."""
    def __init__(self, value=100.0, is_active=True):
        self.domain_name = "player_imc"
        self.value = value
        self.is_active = is_active
        self.config_path = "/Game/YoureFired/Data/DT_PlayerImc"

    def get_summary(self):
        return f"PlayerImc State -> Active: {self.is_active}, Value: {self.value}"
