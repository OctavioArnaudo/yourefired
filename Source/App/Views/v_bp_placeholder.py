# ============================================================
# YOU'RE FIRED - View: Blueprint Placeholder Visualization View
# ============================================================
import unreal
import c_bp_placeholder

def render_bp_placeholders_preview():
    """View: Muestra y renderiza una vista previa de los Blueprints placeholders en el nivel de desarrollo."""
    unreal.log("[View:BP_Placeholder] Generando previsualización de Blueprints placeholders...")
    c_bp_placeholder.spawn_bp_placeholder("Player", (0, 0, 100))
    c_bp_placeholder.spawn_bp_placeholder("OfficeDoor", (0, 300, 100))
