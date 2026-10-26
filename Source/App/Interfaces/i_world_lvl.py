# ============================================================
# YOU'RE FIRED - Interface : WorldLvl
# ============================================================
import unreal

class IWorldLvlInterface:
    """Interface: Contrato para WorldLvl."""
    def execute_world_lvl(self):
        raise NotImplementedError("execute_world_lvl debe ser implementado")
