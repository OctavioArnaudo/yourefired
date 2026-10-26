# ============================================================
# YOU'RE FIRED - Interface : Light
# ============================================================
import unreal

class ILightInterface:
    """Interface: Contrato formal de interacción para Light."""
    def execute_light_contract(self, data):
        raise NotImplementedError("execute_light_contract debe ser implementado")
