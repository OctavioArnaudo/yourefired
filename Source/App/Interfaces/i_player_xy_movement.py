# ============================================================
# YOU'RE FIRED - Interface : PlayerXyMovement
# ============================================================
import unreal

class IPlayerXyMovementInterface:
    """Interface: Contrato formal de interacción para PlayerXyMovement."""
    def execute_player_xy_movement_contract(self, data):
        raise NotImplementedError("execute_player_xy_movement_contract debe ser implementado")
