# ============================================================
# YOU'RE FIRED - Model : Health State & Damage Calculations
# ============================================================
import unreal

class MHealthData:
    """Model: Datos de salud, puntos de vida y calculos de dano."""

    def __init__(self, max_health=100.0):
        self.max_health = float(max_health)
        self.current_health = float(max_health)
        self.b_is_dead = False

    def apply_damage(self, damage_amount):
        damage = max(0.0, float(damage_amount))
        self.current_health = max(0.0, self.current_health - damage)
        if self.current_health <= 0.0:
            self.b_is_dead = True
        unreal.log(f"[MHealthData] Dano aplicado: {damage}. Salud actual: {self.current_health}/{self.max_health}")
        return self.current_health

    def heal(self, heal_amount):
        amount = max(0.0, float(heal_amount))
        self.current_health = min(self.max_health, self.current_health + amount)
        if self.current_health > 0.0:
            self.b_is_dead = False
        unreal.log(f"[MHealthData] Curacion aplicada: {amount}. Salud actual: {self.current_health}/{self.max_health}")
        return self.current_health

    def get_health_ratio(self):
        return self.current_health / self.max_health if self.max_health > 0 else 0.0
