# ============================================================
# YOU'RE FIRED - Model : UaReloader
# ============================================================
import unreal

class MUaReloaderData:
    """Model: Definición de datos, parámetros y estado para UaReloader."""
    def __init__(self, value=100.0, is_active=True):
        self.domain_name = "ua_reloader"
        self.value = value
        self.is_active = is_active
        self.config_path = "/Game/YoureFired/Data/DT_UaReloader"

    def get_summary(self):
        return f"UaReloader State -> Active: {self.is_active}, Value: {self.value}"
