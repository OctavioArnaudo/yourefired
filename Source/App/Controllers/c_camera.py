# ============================================================
# YOU'RE FIRED - Controller: 2D Orthographic Camera Setup
# ============================================================
import unreal

def get_actor_by_label(label):
    for actor in unreal.EditorLevelLibrary.get_all_level_actors():
        if actor and actor.get_actor_label() == label:
            return actor
    return None

def spawn_or_update_camera(label, location=(0, 0, 1500), rotation=(-90, 0, 0), ortho_width=2400.0):
    """Controller: Configura una cámara ortográfica pura en 2D enfocando el plano XY."""
    cam = get_actor_by_label(label)
    if not cam:
        cam = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.CameraActor, unreal.Vector(*location), unreal.Rotator(*rotation))
        if cam:
            cam.set_actor_label(label)
            unreal.log(f"[Controller:Camera] Creada cámara 2D '{label}'.")
    else:
        cam.set_actor_location_and_rotation(unreal.Vector(*location), unreal.Rotator(*rotation), False, True)

    if cam and hasattr(cam, "camera_component") and cam.camera_component:
        cam.camera_component.set_editor_property("projection_mode", unreal.CameraProjectionMode.ORTHOGRAPHIC)
        cam.camera_component.set_editor_property("ortho_width", ortho_width)
    return cam
