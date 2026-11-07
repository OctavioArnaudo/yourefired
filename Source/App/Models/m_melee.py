# ============================================================
# YOU'RE FIRED - Model : Melee
# ============================================================
import unreal

class MMeleeData:
    """Model: Definición de datos y parámetros para el ataque cuerpo a cuerpo (Melee)."""
    def __init__(self, damage=25.0, attack_range=150.0, is_active=True):
        self.domain_name = "melee"
        self.damage = damage
        self.attack_range = attack_range
        self.is_active = is_active

    def get_summary(self):
        return f"Melee State -> Active: {self.is_active}, Damage: {self.damage}, Range: {self.attack_range}"
