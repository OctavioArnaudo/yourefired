# ============================================================
# YOU'RE FIRED - View : Projectile Mesh & Impact Visuals
# ============================================================
import unreal

class VProjectileView:
    """View: Efectos visuales de impacto y estela de proyectil."""

    def play_impact_effect(self, impact_location):
        unreal.log(f"[VProjectileView] Efecto de impacto de proyectil en {impact_location}")
        return True
