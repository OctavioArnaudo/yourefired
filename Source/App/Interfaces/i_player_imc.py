# ============================================================
# YOU'RE FIRED - Interface : PlayerImc
# ============================================================
import unreal

class IPlayerImcInterface:
    """Interface: Contrato formal de interacción para PlayerImc."""
    def execute_player_imc_contract(self, data):
        raise NotImplementedError("execute_player_imc_contract debe ser implementado")
