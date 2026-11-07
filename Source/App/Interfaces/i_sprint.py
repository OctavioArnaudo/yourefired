# ============================================================
# YOU'RE FIRED - Interface : Sprint Contract
# ============================================================
import unreal

class ISprintInterface:
    """Interface: Contrato para activacion/desactivacion de sprint."""

    def set_sprint_enabled(self, b_enable):
        unreal.log(f"[ISprintInterface] Contrato set_sprint_enabled ejecutado: {b_enable}")
        return bool(b_enable)
