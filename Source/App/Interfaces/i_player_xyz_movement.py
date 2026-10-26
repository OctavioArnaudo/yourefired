# ============================================================
# YOU'RE FIRED - Interface : PlayerXyzMovement
# ============================================================
import unreal

class IPlayerXyzMovementInterface:
    """Interface: Contrato formal de interacción para PlayerXyzMovement."""
    def execute_player_xyz_movement_contract(self, data):
        raise NotImplementedError("execute_player_xyz_movement_contract debe ser implementado")
