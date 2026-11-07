# ============================================================
# YOU'RE FIRED - Controller : Projectile Lifecycle Controller
# ============================================================
import unreal

class CProjectileController:
    """Controller: Gestion del ciclo de vida y colision de proyectiles."""

    def initialize_projectile(self, projectile_actor, projectile_model):
        if not projectile_actor or not projectile_model:
            return False
        unreal.log(f"[CProjectileController] Inicializando proyectil {projectile_actor.get_name()} velocidad={projectile_model.speed}")
        return True
