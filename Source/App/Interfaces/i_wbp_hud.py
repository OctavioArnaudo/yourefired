# ============================================================
# YOU'RE FIRED - Interface: HUD UI Contract
# ============================================================
import unreal

class IWbpHudInterface:
    """Interface: Contrato para controladores e interfaces de HUD."""
    def update_stats(self, stress, coffee, signatures):
        raise NotImplementedError("update_stats debe ser implementado")
