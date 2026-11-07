# ============================================================
# YOU'RE FIRED - Interface : Walk Contract
# ============================================================
import unreal

class IWalkInterface:
    """Interface: Contrato para la modificacion del estado de caminata."""

    def toggle_walk_mode(self, b_enable):
        unreal.log(f"[IWalkInterface] Contrato toggle_walk_mode ejecutado con: {b_enable}")
        return bool(b_enable)
