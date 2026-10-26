# ============================================================
# YOU'RE FIRED - Interface : Pickup
# ============================================================
import unreal

class IPickupInterface:
    """Interface: Contrato para Pickup."""
    def execute_pickup(self):
        raise NotImplementedError("execute_pickup debe ser implementado")
