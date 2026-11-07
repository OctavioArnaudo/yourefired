# ============================================================
# YOU'RE FIRED - Model : Raw Placeholder Data
# ============================================================
import unreal

class MRawPlaceholderData:
    """Model: Datos brutos para generacion de placeholders."""

    def __init__(self, width=16, height=16, color_rgba=(255, 0, 128, 255)):
        self.width = width
        self.height = height
        self.color_rgba = color_rgba
