# ============================================================
# YOU'RE FIRED - Model : PlayerXyzMovement
# ============================================================
import unreal

class MPlayerXyzMovementData:
    """Model: Definición de datos, parámetros y estado para PlayerXyzMovement."""
    def __init__(self, value=100.0, is_active=True):
        self.domain_name = "player_xyz_movement"
        self.value = value
        self.is_active = is_active
        self.config_path = "/Game/YoureFired/Data/DT_PlayerXyzMovement"

    def get_summary(self):
        return f"PlayerXyzMovement State -> Active: {self.is_active}, Value: {self.value}"
