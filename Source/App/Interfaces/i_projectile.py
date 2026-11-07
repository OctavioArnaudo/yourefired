# ============================================================
# YOU'RE FIRED - Interface : Projectile Contract
# ============================================================
import unreal

class IProjectileInterface:
    """Interface: Contrato para impacto de proyectiles."""

    def on_projectile_hit(self, hit_actor, damage):
        unreal.log(f"[IProjectileInterface] Evento de impacto de proyectil en {hit_actor.get_name() if hit_actor else 'None'}: dano={damage}")
        return True
