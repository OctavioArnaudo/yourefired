# ============================================================
# YOU'RE FIRED - Model : Weapon
# ============================================================
import unreal

class MWeaponModel:
    """Model: Datos y estado de Weapon."""
    def __init__(self, value=100.0, enabled=True):
        self.value = value
        self.enabled = enabled
        self.name = "Weapon"
