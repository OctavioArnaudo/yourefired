# ============================================================
# YOU'RE FIRED - Interface : UaLoader
# ============================================================
import unreal

class IUaLoaderInterface:
    """Interface: Contrato para UaLoader."""
    def execute_ua_loader(self):
        raise NotImplementedError("execute_ua_loader debe ser implementado")
