# ============================================================
# YOU'RE FIRED - Interface : PilotLvl
# ============================================================
import unreal

class IPilotLvlInterface:
    """Interface: Contrato para PilotLvl."""
    def execute_pilot_lvl(self):
        raise NotImplementedError("execute_pilot_lvl debe ser implementado")
