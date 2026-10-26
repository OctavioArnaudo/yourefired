# ============================================================
# YOU'RE FIRED - Interface : PlayerXMovement
# ============================================================
import unreal

class IPlayerXMovementInterface:
    """Interface: Contrato formal de interacción para PlayerXMovement."""
    def execute_player_x_movement_contract(self, data):
        raise NotImplementedError("execute_player_x_movement_contract debe ser implementado")
