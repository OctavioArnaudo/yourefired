# ============================================================
# YOU'RE FIRED - Interface: Player Character Instance Contract
# ============================================================
import unreal

class IPlayerCharacterInstanceInterface:
    """Interface: Contrato formal para la gestión de instancias del personaje."""
    def initialize_instance(self, location):
        raise NotImplementedError("initialize_instance debe ser implementado")
