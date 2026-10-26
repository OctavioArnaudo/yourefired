# ============================================================
# YOU'RE FIRED - Model : Door
# ============================================================
import unreal

class MDoorData:
    """Model: Definición de datos, parámetros y estado para Door."""
    def __init__(self, value=100.0, is_active=True):
        self.domain_name = "door"
        self.value = value
        self.is_active = is_active
        self.config_path = "/Game/YoureFired/Data/DT_Door"

    def get_summary(self):
        return f"Door State -> Active: {self.is_active}, Value: {self.value}"
