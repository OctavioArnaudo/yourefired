# ============================================================
# YOU'RE FIRED - View: HUD Overlay Visualization
# ============================================================
import unreal
import c_wbp_hud

def render_hud_overlay_view():
    """View: Renderiza la interfaz HUD en la pantalla durante el nivel."""
    unreal.log("[View:WbpHud] Renderizando vista de HUD sobre el nivel activo.")
    c_wbp_hud.update_hud_stats(stress=15.0, coffee=85.0, signatures=2)
