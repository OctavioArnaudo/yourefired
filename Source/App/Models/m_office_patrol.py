# ============================================================
# YOU'RE FIRED - Model : OfficePatrol
# ============================================================
import unreal

class MOfficePatrolData:
    """Model: Definición de datos, parámetros y estado para OfficePatrol."""
    def __init__(self, value=100.0, is_active=True):
        self.domain_name = "office_patrol"
        self.value = value
        self.is_active = is_active
        self.config_path = "/Game/YoureFired/Data/DT_OfficePatrol"

    def get_summary(self):
        return f"OfficePatrol State -> Active: {self.is_active}, Value: {self.value}"
