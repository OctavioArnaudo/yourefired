# ============================================================
# YOU'RE FIRED - Model : OfficeGm
# ============================================================
import unreal

class MOfficeGmData:
    """Model: Definición de datos, parámetros y estado para OfficeGm."""
    def __init__(self, value=100.0, is_active=True):
        self.domain_name = "office_gm"
        self.value = value
        self.is_active = is_active
        self.config_path = "/Game/YoureFired/Data/DT_OfficeGm"

    def get_summary(self):
        return f"OfficeGm State -> Active: {self.is_active}, Value: {self.value}"
