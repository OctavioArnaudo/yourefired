# ============================================================
# YOU'RE FIRED - Interface : StaticPlaceholder
# ============================================================
import unreal

class IStaticPlaceholderInterface:
    """Interface: Contrato formal de interacción para StaticPlaceholder."""
    def execute_static_placeholder_contract(self, data):
        raise NotImplementedError("execute_static_placeholder_contract debe ser implementado")
