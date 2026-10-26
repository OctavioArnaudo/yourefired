# ============================================================
# YOU'RE FIRED - Interface : WbpPlaceholder
# ============================================================
import unreal

class IWbpPlaceholderInterface:
    """Interface: Contrato para WbpPlaceholder."""
    def execute_wbp_placeholder(self):
        raise NotImplementedError("execute_wbp_placeholder debe ser implementado")
