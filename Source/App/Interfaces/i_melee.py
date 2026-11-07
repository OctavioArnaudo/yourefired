# ============================================================
# YOU'RE FIRED - Interface: Melee Contract
# ============================================================
import unreal

class IMeleeInterface:
    """Interface: Contrato exclusivo para acciones cuerpo a cuerpo (Melee)."""
    def execute_melee(self):
        raise NotImplementedError("execute_melee debe ser implementado")
