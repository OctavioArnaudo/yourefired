# ============================================================
# YOU'RE FIRED - Service: Static Asset Placeholders Orchestrator
# ============================================================
import unreal
import s_sm_placeholder
import s_m_placeholder

def ensure_static_placeholders():
    """Service: Verificación exclusiva de Mallas Estáticas (SM_) y Materiales (M_, MI_)."""
    s_sm_placeholder.ensure_sm_placeholders()
    s_m_placeholder.ensure_m_placeholders()
