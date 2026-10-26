# ============================================================
# YOU'RE FIRED - Interface : MainLvl
# ============================================================
import unreal

class IMainLvlInterface:
    """Interface: Contrato para MainLvl."""
    def execute_main_lvl(self):
        raise NotImplementedError("execute_main_lvl debe ser implementado")
