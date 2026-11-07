# ============================================================
# YOU'RE FIRED - Interface: Patrol Contract
# ============================================================
import unreal

class IPatrolInterface:
    """Interface: Contrato exclusivo para funciones de patrullaje."""
    def set_patrol_route(self, route):
        raise NotImplementedError("set_patrol_route debe ser implementado")
