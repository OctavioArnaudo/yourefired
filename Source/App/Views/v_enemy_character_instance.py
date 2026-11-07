# ============================================================
# YOU'RE FIRED - View : Enemy Character Instance Visuals
# ============================================================
import unreal

class VEnemyCharacterInstanceView:
    """View: Visualizacion de icono de alerta y efectos de enemigo."""

    def show_alert_icon(self, enemy_actor, b_visible):
        if enemy_actor:
            unreal.log(f"[VEnemyCharacterInstanceView] Icono de alerta en {enemy_actor.get_name()}: {b_visible}")
            return True
        return False
