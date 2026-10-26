# ============================================================
# YOU'RE FIRED - Interface : Spawner
# ============================================================
import unreal

class ISpawnerInterface:
    """Interface: Contrato para Spawner."""
    def execute_spawner(self):
        raise NotImplementedError("execute_spawner debe ser implementado")
