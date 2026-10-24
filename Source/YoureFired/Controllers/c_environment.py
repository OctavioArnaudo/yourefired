import unreal
from . import c_spawner as spawner

def spawn_ui_elements(title):
    """Component: Crea elementos base para niveles de UI."""
    # Fondo UI
    spawner.spawn_mesh("UI_Backdrop_" + title, "/Engine/BasicShapes/Cube.Cube", (0, 800, 0), (0.5, 30.0, 20.0))

    # Cámara UI
    cam = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.CameraActor, unreal.Vector(0,0,0), unreal.Rotator(0,0,0))
    cam.set_actor_label("UI_Camera_" + title)

    # Luces
    unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.DirectionalLight, unreal.Vector(0,0,500), unreal.Rotator(-30,0,0))
    unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.SkyLight, unreal.Vector(0,0,300), unreal.Rotator(0,0,0))
