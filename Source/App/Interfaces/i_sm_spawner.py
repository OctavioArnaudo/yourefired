# ============================================================
# YOU'RE FIRED - Interface : SmSpawner
# ============================================================
import unreal

class ISmSpawnerInterface:
    """Interface: Contrato para SmSpawner."""
    def execute_sm_spawner(self):
        raise NotImplementedError("execute_sm_spawner debe ser implementado")
