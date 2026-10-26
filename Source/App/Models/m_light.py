# ============================================================
# YOU'RE FIRED - Model : Light
# ============================================================
import unreal

class MLightData:
    """Model: Definición de datos, parámetros y estado para Light."""
    def __init__(self, value=100.0, is_active=True):
        self.domain_name = "light"
        self.value = value
        self.is_active = is_active
        self.config_path = "/Game/YoureFired/Data/DT_Light"

    def get_summary(self):
        return f"Light State -> Active: {self.is_active}, Value: {self.value}"
