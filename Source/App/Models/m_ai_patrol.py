# ============================================================
# YOU'RE FIRED - Model : AiPatrol
# ============================================================
import unreal

class MAiPatrolData:
    """Model: Definición de datos, parámetros y estado para AiPatrol."""
    def __init__(self, value=100.0, is_active=True):
        self.domain_name = "ai_patrol"
        self.value = value
        self.is_active = is_active
        self.config_path = "/Game/YoureFired/Data/DT_AiPatrol"

    def get_summary(self):
        return f"AiPatrol State -> Active: {self.is_active}, Value: {self.value}"
