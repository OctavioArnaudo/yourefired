# ============================================================
# YOU'RE FIRED - Controller : Range Check Controller
# ============================================================
import unreal

class CRangeController:
    """Controller: Verificación de distancias de combate entre entidades."""

    def evaluate_combat_range(self, origin_actor, target_actor, range_model):
        if not origin_actor or not target_actor or not range_model:
            return "Out"
        unreal.log(f"[CRangeController] Evaluando rango entre {origin_actor.get_name()} y {target_actor.get_name()}")
        return "Melee"
