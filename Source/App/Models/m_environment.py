# ============================================================
# YOU'RE FIRED - Model : Environment
# ============================================================
import unreal

class MEnvironmentModel:
    """Model: Datos y estado de Environment."""
    def __init__(self, value=100.0, enabled=True):
        self.value = value
        self.enabled = enabled
        self.name = "Environment"
