# ============================================================
# YOU'RE FIRED - Model : Enemy Character Instance Config
# ============================================================
import unreal

class MEnemyCharacterInstanceData:
    """Model: Configuracion de estado de la instancia enemiga."""

    def __init__(self, patrol_radius=500.0, attack_cooldown=1.5):
        self.patrol_radius = float(patrol_radius)
        self.attack_cooldown = float(attack_cooldown)
        self.b_is_alerted = False

    def set_alerted(self, b_alert):
        self.b_is_alerted = bool(b_alert)
        unreal.log(f"[MEnemyCharacterInstanceData] Estado de alerta: {self.b_is_alerted}")
