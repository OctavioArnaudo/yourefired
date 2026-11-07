# ============================================================
# YOU'RE FIRED - Model : Spawn Configuration Data
# ============================================================
import unreal

class MSpawnData:
    """Model: Datos y configuracion de parametros de spawn."""

    def __init__(self, actor_class_path="/Game/Blueprints/BP_DefaultActor.BP_DefaultActor_C"):
        self.actor_class_path = actor_class_path
        self.spawn_location = (0.0, 0.0, 100.0)
        self.spawn_rotation = (0.0, 0.0, 0.0)
        self.spawn_scale = (1.0, 1.0, 1.0)
        self.b_spawn_adjusted = True

    def set_spawn_location(self, x, y, z):
        self.spawn_location = (float(x), float(y), float(z))

    def set_spawn_rotation(self, roll, pitch, yaw):
        self.spawn_rotation = (float(roll), float(pitch), float(yaw))

    def get_transform_dict(self):
        return {
            "location": self.spawn_location,
            "rotation": self.spawn_rotation,
            "scale": self.spawn_scale
        }
