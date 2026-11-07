# ============================================================
# YOU'RE FIRED - View : Health Bar & Hit Flash Visuals
# ============================================================
import unreal

class VHealthView:
    """View: Visualizacion de barra de vida y destellos de dano."""

    def update_health_bar(self, current_health, max_health):
        ratio = (current_health / max_health) if max_health > 0 else 0.0
        unreal.log(f"[VHealthView] Barra de vida actualizada: {ratio * 100:.1f}%")
        return ratio

    def trigger_damage_flash(self, actor):
        if actor:
            unreal.log(f"[VHealthView] Destello de dano activado en {actor.get_name()}")
            return True
        return False
