# ============================================================
# YOU'RE FIRED - Model : UaNormalizer
# ============================================================
import unreal

class MUaNormalizerModel:
    """Model: Datos y estado de UaNormalizer."""
    def __init__(self, value=100.0, enabled=True):
        self.value = value
        self.enabled = enabled
        self.name = "UaNormalizer"
