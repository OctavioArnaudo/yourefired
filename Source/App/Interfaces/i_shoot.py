# ============================================================
# YOU'RE FIRED - Interface: Shoot Contract
# ============================================================
import unreal

class IShootInterface:
    """Interface: Contrato exclusivo para acciones de disparo a distancia (Shoot)."""
    def execute_shoot(self):
        raise NotImplementedError("execute_shoot debe ser implementado")
