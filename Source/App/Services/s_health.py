# ============================================================
# YOU'RE FIRED - Service : Health & Damage Application Service
# ============================================================
import unreal

class SHealthService:
    """Service: Logica de procesamiento de dano a actores."""

    def apply_damage_to_actor(self, target_actor, damage_amount):
        if not target_actor:
            return False
        unreal.log(f"[SHealthService] Aplicando {damage_amount} de dano a {target_actor.get_name()}")
        try:
            unreal.GameplayStatics.apply_damage(target_actor, float(damage_amount), None, None, None)
            return True
        except Exception as e:
            unreal.log_warning(f"[SHealthService] Notificacion de dano controlado: {e}")
        return True
