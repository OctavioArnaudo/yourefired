# ============================================================
# YOU'RE FIRED - Interface : CoffeePickup
# ============================================================
import unreal

class ICoffeePickupInterface:
    """Interface: Contrato para CoffeePickup."""
    def execute_coffee_pickup(self):
        raise NotImplementedError("execute_coffee_pickup debe ser implementado")
