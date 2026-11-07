# ============================================================
# YOU'RE FIRED - Controller : Spawn Orchestrator
# ============================================================
import unreal

class CSpawnController:
    """Controller: Control de peticiones de spawn y ciclos de vida."""

    def request_spawn(self, spawn_model, service_spawn_ref=None):
        if not spawn_model:
            unreal.log_error("[CSpawnController] Modelo de spawn nulo.")
            return None

        transform = spawn_model.get_transform_dict()
        unreal.log(f"[CSpawnController] Procesando solicitud de spawn para {spawn_model.actor_class_path} en {transform['location']}.")

        if service_spawn_ref:
            return service_spawn_ref.execute_spawn(spawn_model.actor_class_path, transform['location'], transform['rotation'])
        return True
