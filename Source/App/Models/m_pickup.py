# ============================================================
# YOU'RE FIRED - Model : Pickup
# ============================================================
import unreal

class MPickupModel:
    """Model: Datos y estado de Pickup."""
    def __init__(self, value=100.0, enabled=True):
        self.value = value
        self.enabled = enabled
        self.name = "Pickup"
