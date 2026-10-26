# ============================================================
# YOU'RE FIRED - Service: Master Placeholder Orchestrator
# ============================================================
import unreal
import s_sm_placeholder
import s_m_placeholder
import s_bp_placeholder
import s_wbp_placeholder
import s_fb_placeholder

def ensure_asset_placeholders():
    """Service: Orquesta la verificación y generación de placeholders físicos para todos los tipos de assets (SM_, M_, MI_, BP_, WBP_, FB_)."""
    unreal.log("[Service:Placeholder] === INICIANDO VERIFICACION DE PLACEHOLDERS ===")

    if hasattr(s_sm_placeholder, "ensure_sm_placeholders"):
        s_sm_placeholder.ensure_sm_placeholders()
    if hasattr(s_m_placeholder, "ensure_m_placeholders"):
        s_m_placeholder.ensure_m_placeholders()
    if hasattr(s_bp_placeholder, "ensure_bp_placeholders"):
        s_bp_placeholder.ensure_bp_placeholders()
    if hasattr(s_wbp_placeholder, "ensure_wbp_placeholders"):
        s_wbp_placeholder.ensure_wbp_placeholders()
    if hasattr(s_fb_placeholder, "ensure_fb_placeholders"):
        s_fb_placeholder.ensure_fb_placeholders()

    unreal.log("[Service:Placeholder] === VERIFICACION COMPLETADA ===")
