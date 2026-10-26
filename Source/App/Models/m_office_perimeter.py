# ============================================================
# YOU'RE FIRED - Model : OfficePerimeter
# ============================================================
import unreal

class MOfficePerimeterData:
    """Model: Definición de datos, parámetros y estado para OfficePerimeter."""
    def __init__(self, value=100.0, is_active=True):
        self.domain_name = "office_perimeter"
        self.value = value
        self.is_active = is_active
        self.config_path = "/Game/YoureFired/Data/DT_OfficePerimeter"

    def get_summary(self):
        return f"OfficePerimeter State -> Active: {self.is_active}, Value: {self.value}"
