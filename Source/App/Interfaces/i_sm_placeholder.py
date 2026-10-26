# ============================================================
# YOU'RE FIRED - Interface : SmPlaceholder
# ============================================================
import unreal

class ISmPlaceholderInterface:
    """Interface: Contrato para SmPlaceholder."""
    def execute_sm_placeholder(self):
        raise NotImplementedError("execute_sm_placeholder debe ser implementado")
