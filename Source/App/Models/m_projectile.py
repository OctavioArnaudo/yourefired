# ============================================================
# YOU'RE FIRED - Model : Projectile Properties
# ============================================================
import unreal

class MProjectileData:
    """Model: Propiedades y especificacion de proyectiles."""

    def __init__(self, speed=3000.0, damage=25.0, lifespan=5.0):
        self.speed = float(speed)
        self.damage = float(damage)
        self.lifespan = float(lifespan)
        self.mesh_path = "/Game/Meshes/SM_Projectile.SM_Projectile"

    def get_launch_params(self):
        return {"speed": self.speed, "damage": self.damage, "lifespan": self.lifespan}
