# ============================================================
# YOU'RE FIRED - Interface : Gm
# ============================================================
import unreal

class IGmInterface:
    """Interface: Contrato para Gm."""
    def execute_gm(self):
        raise NotImplementedError("execute_gm debe ser implementado")
