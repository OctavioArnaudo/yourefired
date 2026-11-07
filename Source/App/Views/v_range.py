# ============================================================
# YOU'RE FIRED - View : Debug Range Indicators
# ============================================================
import unreal

class VRangeView:
    """View: Representacion de esferas de depuracion de rango de ataque."""

    def draw_debug_range(self, location, radius):
        unreal.log(f"[VRangeView] Dibujando radio de depuracion {radius} en {location}")
        return True
