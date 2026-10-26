# ============================================================
# YOU'RE FIRED - Interface : UaReloader
# ============================================================
import unreal

class IUaReloaderInterface:
    """Interface: Contrato formal de interacción para UaReloader."""
    def execute_ua_reloader_contract(self, data):
        raise NotImplementedError("execute_ua_reloader_contract debe ser implementado")
