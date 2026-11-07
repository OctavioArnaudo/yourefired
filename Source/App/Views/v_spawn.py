# ============================================================
# YOU'RE FIRED - View : Spawn Visual Effects & Meshes
# ============================================================
import unreal

class VSpawnView:
    """View: Visualizacion e indicadores de puntos de spawn."""

    def render_spawn_effect(self, location):
        unreal.log(f"[VSpawnView] Renderizando efecto visual de spawn en {location}.")
        return True

    def apply_spawn_indicator(self, actor):
        if actor:
            unreal.log(f"[VSpawnView] Aplicador de indicador visual adjuntado a {actor.get_name()}.")
            return True
        return False
