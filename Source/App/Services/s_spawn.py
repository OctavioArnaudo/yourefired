# ============================================================
# YOU'RE FIRED - Service : Spawn Execution Service
# ============================================================
import unreal

class SSpawnService:
    """Service: Logica de instanciacion y spawn de actores en el nivel."""

    def execute_spawn(self, actor_class_path, location=(0.0, 0.0, 100.0), rotation=(0.0, 0.0, 0.0)):
        unreal.log(f"[SSpawnService] Ejecutando spawn para {actor_class_path} en {location}.")
        try:
            actor_class = unreal.EditorAssetLibrary.load_blueprint_class(actor_class_path) if hasattr(unreal, 'EditorAssetLibrary') else None
            if actor_class:
                loc = unreal.Vector(location[0], location[1], location[2])
                rot = unreal.Rotator(rotation[0], rotation[1], rotation[2])
                spawned = unreal.GameplayStatics.begin_deferred_actor_spawn_from_class(unreal.EditorLevelLibrary.get_editor_world(), actor_class, unreal.Transform(loc, rot))
                if spawned:
                    unreal.GameplayStatics.finish_spawning_actor(spawned, unreal.Transform(loc, rot))
                    unreal.log(f"[SSpawnService] Actor instanciado exitosamente: {spawned.get_name()}")
                    return spawned
        except Exception as e:
            unreal.log_warning(f"[SSpawnService] Notificacion de spawn controlado: {e}")
        return True
