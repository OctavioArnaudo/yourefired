# ============================================================
# YOU'RE FIRED - Model : OfficeCubicles
# ============================================================
import unreal

class MOfficeCubiclesData:
    """Model: Definición de datos, parámetros y estado para OfficeCubicles."""
    def __init__(self, value=100.0, is_active=True):
        self.domain_name = "office_cubicles"
        self.value = value
        self.is_active = is_active
        self.config_path = "/Game/YoureFired/Data/DT_OfficeCubicles"

    def get_summary(self):
        return f"OfficeCubicles State -> Active: {self.is_active}, Value: {self.value}"
