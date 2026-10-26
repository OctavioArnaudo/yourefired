# ============================================================
# YOU'RE FIRED - Interface: Blueprint Placeholder Contract
# ============================================================
import unreal

class IBPPlaceholderProvider:
    """Interface: Contrato para proveedores de Blueprints Placeholders."""
    def ensure_placeholders(self):
        raise NotImplementedError("ensure_placeholders debe ser implementado")

    def get_placeholder_class(self, name):
        raise NotImplementedError("get_placeholder_class debe ser implementado")
