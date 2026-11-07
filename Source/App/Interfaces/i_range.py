# ============================================================
# YOU'RE FIRED - Interface : Range Contract
# ============================================================
import unreal

class IRangeInterface:
    """Interface: Contrato para verificacion de alcance."""

    def is_target_in_range(self, target_actor, max_range):
        unreal.log(f"[IRangeInterface] Verificando alcance maximo {max_range}")
        return True
