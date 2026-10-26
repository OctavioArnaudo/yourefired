# ============================================================
# YOU'RE FIRED - Interface : Enemy
# ============================================================
import unreal

class IEnemyInterface:
    """Interface: Contrato para Enemy."""
    def execute_enemy(self):
        raise NotImplementedError("execute_enemy debe ser implementado")
