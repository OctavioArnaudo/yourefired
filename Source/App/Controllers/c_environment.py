# ============================================================
# YOU'RE FIRED - Controller: Environment Lighting, Camera & UI Elements
# ============================================================
import unreal
import c_sm_spawner as mesh_spawner
import c_camera
import c_light

CUBE_PATH = "/Engine/BasicShapes/Cube.Cube"

def spawn_ui_elements(title):
    """Component: Crea elementos base e interactivos para niveles de UI con botones 3D visibles e iluminación brillante."""
    # 1. Fondo UI (Azul Real Brillante)
    backdrop_label = "UI_Backdrop_" + title
    mesh_spawner.spawn_mesh(backdrop_label, CUBE_PATH, (0, 800, 0), (0.5, 30.0, 20.0))

    # 2. Cámara UI enfocando al frente
    c_camera.spawn_or_update_camera("UI_Camera_" + title, (0, 0, 100), (0, 0, 0))

    # 3. Luces brillantes en tiempo real (Movable) para iluminar el fondo y botones
    c_light.setup_directional_light("UI_DirectionalLight_" + title, (0, 200, 500), (-45, -90, 0), 15.0)
    c_light.setup_sky_light("UI_SkyLight_" + title, (0, 200, 300), 5.0)

    # 4. Botones 3D visibles en pantalla según el tipo de nivel UI
    if title == "Main":
        mesh_spawner.spawn_mesh("UI_Button_Start", CUBE_PATH, (-200, 750, 150), (0.2, 3.5, 1.2))
        mesh_spawner.spawn_mesh("UI_Button_Settings", CUBE_PATH, (-200, 750, 0), (0.2, 3.5, 1.2))
        mesh_spawner.spawn_mesh("UI_Button_Quit", CUBE_PATH, (-200, 750, -150), (0.2, 3.5, 1.2))
    elif title == "Settings":
        mesh_spawner.spawn_mesh("UI_Button_Settings", CUBE_PATH, (-200, 750, 100), (0.2, 4.0, 1.0))
        mesh_spawner.spawn_mesh("UI_Button_Quit", CUBE_PATH, (-200, 750, -100), (0.2, 3.0, 1.0))
    elif title in ["Victory", "Defeat"]:
        mesh_spawner.spawn_mesh("UI_Button_Start", CUBE_PATH, (-200, 750, 50), (0.2, 4.0, 1.2))
        mesh_spawner.spawn_mesh("UI_Button_Quit", CUBE_PATH, (-200, 750, -100), (0.2, 3.0, 1.0))
