# ============================================================
# YOU'RE FIRED - Interface : UaNormalizer
# ============================================================
import unreal

class IUaNormalizerInterface:
    """Interface: Contrato para UaNormalizer."""
    def execute_ua_normalizer(self):
        raise NotImplementedError("execute_ua_normalizer debe ser implementado")
