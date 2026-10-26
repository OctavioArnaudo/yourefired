# ============================================================
# YOU'RE FIRED - Interface: Unitary Player Movement Contract
# ============================================================
import unreal

class IPlayerMovementInterface:
    """Interface: Contrato para controladores de movimiento 2D."""
    def apply_movement(self, character, input_vector):
        raise NotImplementedError("apply_movement debe ser implementado")
