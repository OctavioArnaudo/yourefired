# ============================================================
# YOU'RE FIRED - Model : Patrol
# ============================================================
import unreal

class MPatrolData:
    """Model: Definición de datos, parámetros y estado para Patrol."""
    def __init__(self, patrol_radius=500.0, is_active=True):
        self.domain_name = "patrol"
        self.patrol_radius = patrol_radius
        self.is_active = is_active
        self.config_path = "/Game/YoureFired/Data/DT_Patrol"

    def get_summary(self):
        return f"Patrol State -> Active: {self.is_active}, Radius: {self.patrol_radius}"
