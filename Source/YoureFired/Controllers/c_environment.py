import unreal
from . import c_spawner as spawner

def spawn_ui_elements(title):
    """Component: Crea elementos base para niveles de UI con iluminación brillante."""
    # Fondo UI
    spawner.spawn_mesh("UI_Backdrop_" + title, "/Engine/BasicShapes/Cube.Cube", (0, 800, 0), (0.5, 30.0, 20.0))

    # Cámara UI
    cam = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.CameraActor, unreal.Vector(0,0,0), unreal.Rotator(0,0,0))
    cam.set_actor_label("UI_Camera_" + title)

    # Luces brillantes para evitar oscuridad
    dir_light = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.DirectionalLight, unreal.Vector(0,0,500), unreal.Rotator(-30,0,0))
    if dir_light:
        dir_light.light_component.set_editor_property("intensity", 10.0)

    skylight = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.SkyLight, unreal.Vector(0,0,300), unreal.Rotator(0,0,0))
    if skylight:
        skylight.light_component.set_editor_property("intensity", 2.0)
