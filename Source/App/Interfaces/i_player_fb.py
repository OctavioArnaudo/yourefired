# ============================================================
# YOU'RE FIRED - Interface : PlayerFb
# ============================================================
import unreal

class IPlayerFbInterface:
    """Interface: Contrato formal de interacción para PlayerFb."""
    def execute_player_fb_contract(self, data):
        raise NotImplementedError("execute_player_fb_contract debe ser implementado")
