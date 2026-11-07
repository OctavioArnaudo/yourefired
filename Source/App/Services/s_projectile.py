# ============================================================
# YOU'RE FIRED - Service : Projectile Launch Service
# ============================================================
import unreal

class SProjectileService:
    """Service: Logica de disparo y lanzamiento de proyectiles."""

    def launch_projectile(self, owner_actor, spawn_location, direction, speed=3000.0):
        if not owner_actor:
            return False
        unreal.log(f"[SProjectileService] Lanzando proyectil desde {spawn_location} direccion={direction} vel={speed}")
        return True
