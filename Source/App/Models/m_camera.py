# ============================================================
# YOU'RE FIRED - Model : Camera
# ============================================================
import unreal

class MCameraData:
    """Model: Definición de datos, parámetros y estado para Camera."""
    def __init__(self, value=100.0, is_active=True):
        self.domain_name = "camera"
        self.value = value
        self.is_active = is_active
        self.config_path = "/Game/YoureFired/Data/DT_Camera"

    def get_summary(self):
        return f"Camera State -> Active: {self.is_active}, Value: {self.value}"
