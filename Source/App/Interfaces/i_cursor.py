# ============================================================
# YOU'RE FIRED - Interface : Cursor Contract
# ============================================================
import unreal

class ICursorInterface:
    """Interface: Contrato para apuntado por cursor."""

    def get_cursor_target_location(self):
        unreal.log("[ICursorInterface] Solicitando ubicacion objetivo del cursor.")
        return (0.0, 0.0, 0.0)
