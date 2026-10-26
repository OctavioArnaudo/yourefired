# ============================================================
# YOU'RE FIRED - Model : UaLoader
# ============================================================
import unreal

class MUaLoaderModel:
    """Model: Datos y estado de UaLoader."""
    def __init__(self, value=100.0, enabled=True):
        self.value = value
        self.enabled = enabled
        self.name = "UaLoader"
