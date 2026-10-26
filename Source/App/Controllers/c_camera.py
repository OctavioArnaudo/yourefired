# ============================================================
# YOU'RE FIRED - Controller: Camera Setup & Positioning
# ============================================================
import unreal

def get_actor_by_label(label):
    for actor in unreal.EditorLevelLibrary.get_all_level_actors():
        if actor and actor.get_actor_label() == label:
            return actor
    return None

def spawn_or_update_camera(label, location, rotation):
    """Controller: Reutiliza o crea una cámara con la ubicación y rotación dadas."""
    cam = get_actor_by_label(label)
    if not cam:
        cam = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.CameraActor, unreal.Vector(*location), unreal.Rotator(*rotation))
        if cam:
            cam.set_actor_label(label)
            unreal.log(f"[Controller:Camera] Creada cámara '{label}'.")
    else:
        cam.set_actor_location_and_rotation(unreal.Vector(*location), unreal.Rotator(*rotation), False, True)
        unreal.log(f"[Controller:Camera] Reutilizada cámara '{label}'.")
    return cam
