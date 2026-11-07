# ============================================================
# YOU'RE FIRED - View : Crosshair & Cursor Decal
# ============================================================
import unreal

class VCursorView:
    """View: Renders de la reticula de apuntado y decal en suelo."""

    def draw_crosshair(self, screen_position):
        unreal.log(f"[VCursorView] Dibujando reticula en posicion de pantalla {screen_position}")
        return True
