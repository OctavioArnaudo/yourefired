# ============================================================
# YOU'RE FIRED - Model : OfficeActors
# ============================================================
import unreal

class MOfficeActorsData:
    """Model: Definición de datos, parámetros y estado para OfficeActors."""
    def __init__(self, value=100.0, is_active=True):
        self.domain_name = "office_actors"
        self.value = value
        self.is_active = is_active
        self.config_path = "/Game/YoureFired/Data/DT_OfficeActors"

    def get_summary(self):
        return f"OfficeActors State -> Active: {self.is_active}, Value: {self.value}"
