# ============================================================
# YOU'RE FIRED - Interface : DefeatLvl
# ============================================================
import unreal

class IDefeatLvlInterface:
    """Interface: Contrato para DefeatLvl."""
    def execute_defeat_lvl(self):
        raise NotImplementedError("execute_defeat_lvl debe ser implementado")
