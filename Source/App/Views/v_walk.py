# ============================================================
# YOU'RE FIRED - View : Walk Animation & Footsteps
# ============================================================
import unreal

class VWalkView:
    """View: Efectos de audio y animacion para la caminata."""

    def play_footstep_sound(self, surface_type="Concrete"):
        unreal.log(f"[VWalkView] Reproduciendo sonido de pisada para superficie: {surface_type}")
        return True
