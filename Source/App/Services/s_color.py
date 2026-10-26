# ============================================================
# YOU'RE FIRED - Service: Object Color Resolution
# ============================================================
import unreal
import m_color

def get_color_for_name(name):
    """Service: Retorna el LinearColor correspondiente consultando el modelo m_color."""
    for key, color in m_color.COLOR_PALETTE.items():
        if key in name:
            return color
    return unreal.LinearColor(0.5, 0.5, 0.5, 1.0)
