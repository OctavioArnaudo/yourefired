# ============================================================
# YOU'RE FIRED - Interface : SignaturePickup
# ============================================================
import unreal

class ISignaturePickupInterface:
    """Interface: Contrato para SignaturePickup."""
    def execute_signature_pickup(self):
        raise NotImplementedError("execute_signature_pickup debe ser implementado")
