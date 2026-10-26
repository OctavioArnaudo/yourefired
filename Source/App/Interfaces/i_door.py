# ============================================================
# YOU'RE FIRED - Interface : Door
# ============================================================
import unreal

class IDoorInterface:
    """Interface: Contrato para Door."""
    def execute_door(self):
        raise NotImplementedError("execute_door debe ser implementado")
