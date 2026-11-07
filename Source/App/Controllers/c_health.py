# ============================================================
# YOU'RE FIRED - Controller : Health Events & Damage Dispatch
# ============================================================
import unreal

class CHealthController:
    """Controller: Orquestador de eventos de dano y muerte."""

    def process_damage_event(self, health_model, damage_amount, service_ref=None):
        if not health_model:
            return False
        new_hp = health_model.apply_damage(damage_amount)
        if health_model.b_is_dead:
            unreal.log(f"[CHealthController] Objetivo muerto (HP: {new_hp}).")
        return True
