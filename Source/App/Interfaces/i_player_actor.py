# ============================================================
# YOU'RE FIRED - Interface : PlayerActor
# ============================================================
import unreal

class IPlayerActorInterface:
    """Interface: Contrato para PlayerActor."""
    def execute_player_actor(self):
        raise NotImplementedError("execute_player_actor debe ser implementado")
