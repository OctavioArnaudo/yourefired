# ============================================================
# YOU'RE FIRED - Interface : Lvl
# ============================================================
import unreal

class ILvlInterface:
    """Interface: Contrato para Lvl."""
    def execute_lvl(self):
        raise NotImplementedError("execute_lvl debe ser implementado")
