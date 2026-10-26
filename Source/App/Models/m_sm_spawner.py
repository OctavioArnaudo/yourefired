# ============================================================
# YOU'RE FIRED - Model : SmSpawner
# ============================================================
import unreal

class MSmSpawnerModel:
    """Model: Datos y estado de SmSpawner."""
    def __init__(self, value=100.0, enabled=True):
        self.value = value
        self.enabled = enabled
        self.name = "SmSpawner"
