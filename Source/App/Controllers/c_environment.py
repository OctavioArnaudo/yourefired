import unreal
import c_sm_spawner as mesh_spawner

def get_actor_by_label(label):
    """Encuentra un actor existente en el nivel activo por su etiqueta para evitar duplicados."""
    for actor in unreal.EditorLevelLibrary.get_all_level_actors():
        if actor and actor.get_actor_label() == label:
            return actor
    return None

def spawn_ui_elements(title):
    """Component: Reutiliza o crea elementos base para niveles de UI con iluminación en tiempo real sin duplicados."""
    backdrop_label = "UI_Backdrop_" + title
    mesh_spawner.spawn_mesh(backdrop_label, "/Engine/BasicShapes/Cube.Cube", (0, 800, 0), (0.5, 30.0, 20.0))

    # Cámara UI
    cam_label = "UI_Camera_" + title
    cam = get_actor_by_label(cam_label)
    if not cam:
        cam = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.CameraActor, unreal.Vector(0,0,0), unreal.Rotator(0,0,0))
        if cam:
            cam.set_actor_label(cam_label)
    else:
        cam.set_actor_location_and_rotation(unreal.Vector(0,0,0), unreal.Rotator(0,0,0), False, True)

    # DirectionalLight
    dir_label = "UI_DirectionalLight_" + title
    dir_light = get_actor_by_label(dir_label)
    if not dir_light:
        dir_light = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.DirectionalLight, unreal.Vector(0,0,500), unreal.Rotator(-30,0,0))
        if dir_light:
            dir_light.set_actor_label(dir_label)
    else:
        dir_light.set_actor_location_and_rotation(unreal.Vector(0,0,500), unreal.Rotator(-30,0,0), False, True)

    if dir_light:
        if hasattr(dir_light, "root_component") and dir_light.root_component:
            dir_light.root_component.set_editor_property("mobility", unreal.ComponentMobility.MOVABLE)
        dir_light.light_component.set_editor_property("intensity", 10.0)

    # SkyLight
    sky_label = "UI_SkyLight_" + title
    skylight = get_actor_by_label(sky_label)
    if not skylight:
        skylight = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.SkyLight, unreal.Vector(0,0,300), unreal.Rotator(0,0,0))
        if skylight:
            skylight.set_actor_label(sky_label)
    else:
        skylight.set_actor_location_and_rotation(unreal.Vector(0,0,300), unreal.Rotator(0,0,0), False, True)

    if skylight:
        if hasattr(skylight, "root_component") and skylight.root_component:
            skylight.root_component.set_editor_property("mobility", unreal.ComponentMobility.MOVABLE)
        skylight.light_component.set_editor_property("intensity", 2.0)
