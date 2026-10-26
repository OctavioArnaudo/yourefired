# ============================================================
# YOU'RE FIRED - Interface : ActorSpawner
# ============================================================
import unreal

class IActorSpawnerInterface:
    """Interface: Contrato para ActorSpawner."""
    def execute_actor_spawner(self):
        raise NotImplementedError("execute_actor_spawner debe ser implementado")
