# ============================================================
# YOU'RE FIRED - Interface : OfficeItems
# ============================================================
import unreal

class IOfficeItemsInterface:
    """Interface: Contrato formal de interacción para OfficeItems."""
    def execute_office_items_contract(self, data):
        raise NotImplementedError("execute_office_items_contract debe ser implementado")
