# ============================================================
# YOU'RE FIRED - Interface : SupervisorEnemy
# ============================================================
import unreal

class ISupervisorEnemyInterface:
    """Interface: Contrato para SupervisorEnemy."""
    def execute_supervisor_enemy(self):
        raise NotImplementedError("execute_supervisor_enemy debe ser implementado")
