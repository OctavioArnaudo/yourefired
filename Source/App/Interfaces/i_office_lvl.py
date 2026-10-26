# ============================================================
# YOU'RE FIRED - Interface : OfficeLvl
# ============================================================
import unreal

class IOfficeLvlInterface:
    """Interface: Contrato para OfficeLvl."""
    def execute_office_lvl(self):
        raise NotImplementedError("execute_office_lvl debe ser implementado")
