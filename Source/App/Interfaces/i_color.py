# ============================================================
# YOU'RE FIRED - Interface : Color
# ============================================================
import unreal

class IColorInterface:
    """Interface: Contrato para Color."""
    def execute_color(self):
        raise NotImplementedError("execute_color debe ser implementado")
