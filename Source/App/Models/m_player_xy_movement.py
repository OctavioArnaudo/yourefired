# ============================================================
# YOU'RE FIRED - Model : PlayerXyMovement
# ============================================================
import unreal

class MPlayerXyMovementData:
    """Model: Definición de datos, parámetros y estado para PlayerXyMovement."""
    def __init__(self, value=100.0, is_active=True):
        self.domain_name = "player_xy_movement"
        self.value = value
        self.is_active = is_active
        self.config_path = "/Game/YoureFired/Data/DT_PlayerXyMovement"

    def get_summary(self):
        return f"PlayerXyMovement State -> Active: {self.is_active}, Value: {self.value}"
