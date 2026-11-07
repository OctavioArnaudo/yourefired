# ============================================================
# YOU'RE FIRED - Model : Shoot
# ============================================================
import unreal

class MShootData:
    """Model: Definición de datos y parámetros para el disparo a distancia (Shoot)."""
    def __init__(self, speed=1000.0, is_active=True):
        self.domain_name = "shoot"
        self.speed = speed
        self.is_active = is_active

    def get_summary(self):
        return f"Shoot State -> Active: {self.is_active}, Speed: {self.speed}"
