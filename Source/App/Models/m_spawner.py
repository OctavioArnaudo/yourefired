# ============================================================
# YOU'RE FIRED - Model : Spawner
# ============================================================
import unreal

class MSpawnerModel:
    """Model: Datos y estado de Spawner."""
    def __init__(self, value=100.0, enabled=True):
        self.value = value
        self.enabled = enabled
        self.name = "Spawner"
