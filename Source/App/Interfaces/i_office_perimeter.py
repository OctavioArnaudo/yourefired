# ============================================================
# YOU'RE FIRED - Interface : OfficePerimeter
# ============================================================
import unreal

class IOfficePerimeterInterface:
    """Interface: Contrato formal de interacción para OfficePerimeter."""
    def execute_office_perimeter_contract(self, data):
        raise NotImplementedError("execute_office_perimeter_contract debe ser implementado")
