# ============================================================
# YOU'RE FIRED - Model : Enemy
# ============================================================
import unreal

class MEnemyData:
    """Model: Definición de datos, parámetros y estado para Enemy."""
    def __init__(self, value=100.0, is_active=True):
        self.domain_name = "enemy"
        self.value = value
        self.is_active = is_active
        self.config_path = "/Game/YoureFired/Data/DT_Enemy"

    def get_summary(self):
        return f"Enemy State -> Active: {self.is_active}, Value: {self.value}"
