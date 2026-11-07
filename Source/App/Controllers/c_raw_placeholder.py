# ============================================================
# YOU'RE FIRED - Controller : Raw Placeholder Controller
# ============================================================
import unreal

class CRawPlaceholderController:
    """Controller: Gestion de la generacion de placeholders raw."""

    def request_raw_placeholder(self, width=16, height=16):
        unreal.log(f"[CRawPlaceholderController] Solicitando placeholder raw ({width}x{height})")
        return True
