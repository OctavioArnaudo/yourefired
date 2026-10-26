# ============================================================
# YOU'RE FIRED - Interface : OfficePatrol
# ============================================================
import unreal

class IOfficePatrolInterface:
    """Interface: Contrato formal de interacción para OfficePatrol."""
    def execute_office_patrol_contract(self, data):
        raise NotImplementedError("execute_office_patrol_contract debe ser implementado")
