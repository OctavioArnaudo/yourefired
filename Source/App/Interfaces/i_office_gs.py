# ============================================================
# YOU'RE FIRED - Interface : OfficeGs
# ============================================================
import unreal

class IOfficeGsInterface:
    """Interface: Contrato para OfficeGs."""
    def execute_office_gs(self):
        raise NotImplementedError("execute_office_gs debe ser implementado")
