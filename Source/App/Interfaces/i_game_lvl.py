# ============================================================
# YOU'RE FIRED - Interface : GameLvl
# ============================================================
import unreal

class IGameLvlInterface:
    """Interface: Contrato formal de interacción para GameLvl."""
    def execute_game_lvl_contract(self, data):
        raise NotImplementedError("execute_game_lvl_contract debe ser implementado")
