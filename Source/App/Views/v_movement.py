# ============================================================
# YOU'RE FIRED - View : Movement FX & Trail Particles
# ============================================================
import unreal

class VMovementView:
    """View: Efectos visuales de rastro y polvo al moverse."""

    def spawn_dust_trail(self, location):
        unreal.log(f"[VMovementView] Particulas de polvo en {location}")
        return True
