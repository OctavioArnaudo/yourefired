# ============================================================
# YOU'RE FIRED - Interface : Movement Contract
# ============================================================
import unreal

class IMovementInterface:
    """Interface: Contrato para movimiento de entidades."""

    def apply_movement_input(self, direction, scale):
        unreal.log(f"[IMovementInterface] Contrato de movimiento invocado: dir={direction}, scale={scale}")
        return True
