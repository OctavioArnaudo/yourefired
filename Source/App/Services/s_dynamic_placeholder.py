# ============================================================
# YOU'RE FIRED - Service: Dynamic Asset Placeholders Orchestrator
# ============================================================
import unreal
import s_bp_placeholder
import s_wbp_placeholder
import s_fb_placeholder

def ensure_dynamic_placeholders():
    """Service: Verificación exclusiva de Blueprints (BP_), Widgets (WBP_) y Flipbooks 2D (FB_)."""
    s_bp_placeholder.ensure_bp_placeholders()
    s_wbp_placeholder.ensure_wbp_placeholders()
    s_fb_placeholder.ensure_fb_placeholders()
