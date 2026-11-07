# ============================================================
# YOU'RE FIRED - Interface : Enemy Character Instance Contract
# ============================================================
import unreal

class IEnemyCharacterInstanceInterface:
    """Interface: Contrato para la instancia de personaje enemigo."""

    def execute_enemy_behavior(self, enemy_actor):
        if not enemy_actor:
            return False
        unreal.log(f"[IEnemyCharacterInstanceInterface] Ejecutando comportamiento para {enemy_actor.get_name()}")
        return True
