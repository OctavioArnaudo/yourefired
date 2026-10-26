# ============================================================
# YOU'RE FIRED - Model : PlayerXMovement
# ============================================================
import unreal

class MPlayerXMovementData:
    """Model: Definición de datos, parámetros y estado para PlayerXMovement."""
    def __init__(self, value=100.0, is_active=True):
        self.domain_name = "player_x_movement"
        self.value = value
        self.is_active = is_active
        self.config_path = "/Game/YoureFired/Data/DT_PlayerXMovement"

    def get_summary(self):
        return f"PlayerXMovement State -> Active: {self.is_active}, Value: {self.value}"
