# ============================================================
# YOU'RE FIRED - Interface : MPlaceholder
# ============================================================
import unreal

class IMPlaceholderInterface:
    """Interface: Contrato para MPlaceholder."""
    def execute_m_placeholder(self):
        raise NotImplementedError("execute_m_placeholder debe ser implementado")
