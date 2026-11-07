# ============================================================
# YOU'RE FIRED - Model : Shoot Configuration & Cadence State
# ============================================================
import unreal

class MShootData:
    """Model: Definición de datos, parámetros y cadencia para el disparo a distancia discreto."""

    def __init__(self, speed=1000.0, fire_rate=0.25, is_active=True):
        self.domain_name = "shoot"
        self.speed = float(speed)
        self.fire_rate = float(fire_rate)  # Tiempo minimo en segundos entre disparos discretos
        self.last_fire_time = 0.0
        self.b_is_firing = False
        self.is_active = is_active

    def can_fire(self, current_time):
        if not self.is_active:
            return False
        return (current_time - self.last_fire_time) >= self.fire_rate

    def record_shot(self, current_time):
        self.last_fire_time = float(current_time)

    def get_summary(self):
        return f"Shoot State -> Active: {self.is_active}, Speed: {self.speed}, FireRate: {self.fire_rate}s, Firing: {self.b_is_firing}"
