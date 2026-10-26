# ============================================================
# YOU'RE FIRED - Interface : PlayerCharacter
# ============================================================
import unreal

class IPlayerCharacterInterface:
    """Interface: Contrato para PlayerCharacter."""
    def execute_player_character(self):
        raise NotImplementedError("execute_player_character debe ser implementado")
