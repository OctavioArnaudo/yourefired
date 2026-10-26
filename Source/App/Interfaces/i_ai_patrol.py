# ============================================================
# YOU'RE FIRED - Interface: AI Patrol Contract
# ============================================================
import unreal

class IAiPatrolInterface:
    """Interface: Contrato para controladores de patrulla de IA."""
    def assign_route(self, enemy_actor, route_name):
        raise NotImplementedError("assign_route debe ser implementado")
