# ============================================================
# YOU'RE FIRED - Interface : Spawn Contract
# ============================================================
import unreal

class ISpawnInterface:
    """Interface: Contrato para operaciones de aparicion y ejecucion de Spawners."""

    def validate_spawn_params(self, actor_class_path, location, rotation):
        """Valida los parametros de aparicion antes de ejecutar el spawn."""
        if not actor_class_path:
            unreal.log_warning("[ISpawnInterface] Ruta de clase invalida para el spawn.")
            return False
        unreal.log(f"[ISpawnInterface] Parametros de spawn validados para {actor_class_path} en {location}.")
        return True

    def prepare_spawn_transform(self, location=(0.0, 0.0, 0.0), rotation=(0.0, 0.0, 0.0), scale=(1.0, 1.0, 1.0)):
        """Prepara y retorna una estructura de transformacion para el spawn."""
        return {
            "location": unreal.Vector(location[0], location[1], location[2]),
            "rotation": unreal.Rotator(rotation[0], rotation[1], rotation[2]),
            "scale": unreal.Vector(scale[0], scale[1], scale[2])
        }

    def on_actor_spawned(self, spawned_actor):
        """Callback ejecutado tras completar la aparicion de un actor."""
        if spawned_actor:
            unreal.log(f"[ISpawnInterface] Actor aparecido exitosamente: {spawned_actor.get_name()}")
            return True
        return False
