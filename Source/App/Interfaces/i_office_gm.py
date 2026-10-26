# ============================================================
# YOU'RE FIRED - Interface : OfficeGm
# ============================================================
import unreal

class IOfficeGmInterface:
    """Interface: Contrato para OfficeGm."""
    def execute_office_gm(self):
        raise NotImplementedError("execute_office_gm debe ser implementado")
