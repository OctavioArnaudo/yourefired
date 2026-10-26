import unreal
import c_sm_spawner as mesh_spawner
import c_camera
import c_light

def spawn_ui_elements(title):
    """Component: Crea elementos base para niveles de UI con iluminación y cámara modulares."""
    backdrop_label = "UI_Backdrop_" + title
    mesh_spawner.spawn_mesh(backdrop_label, "/Engine/BasicShapes/Cube.Cube", (0, 800, 0), (0.5, 30.0, 20.0))

    c_camera.spawn_or_update_camera("UI_Camera_" + title, (0, 0, 0), (0, 0, 0))
    c_light.setup_directional_light("UI_DirectionalLight_" + title, (0, 0, 500), (-30, 0, 0), 10.0)
    c_light.setup_sky_light("UI_SkyLight_" + title, (0, 0, 300), 2.0)
