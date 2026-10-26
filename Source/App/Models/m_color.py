# ============================================================
# YOU'RE FIRED - Model : Color
# ============================================================
import unreal

class MColorModel:
    """Model: Datos y estado de Color."""
    def __init__(self, value=100.0, enabled=True):
        self.value = value
        self.enabled = enabled
        self.name = "Color"
