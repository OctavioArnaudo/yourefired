# ============================================================
# YOU'RE FIRED - Interface : OfficeActors
# ============================================================
import unreal

class IOfficeActorsInterface:
    """Interface: Contrato formal de interacción para OfficeActors."""
    def execute_office_actors_contract(self, data):
        raise NotImplementedError("execute_office_actors_contract debe ser implementado")
