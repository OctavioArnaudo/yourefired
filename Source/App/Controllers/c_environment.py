# ============================================================
# YOU'RE FIRED - Controller: 2D XY Environment, Camera & UI Elements
# ============================================================
import unreal
import c_sm_spawner as mesh_spawner
import c_camera
import c_light

CUBE_PATH = "/Engine/BasicShapes/Cube.Cube"

def spawn_or_update_text_label(label, text, location, world_size=50.0, color=None):
    """Component: Spawnea/actualiza texto 3D orientado al plano 2D XY (mirando a la cámara superior)."""
    if color is None:
        color = unreal.Color(255, 255, 255, 255)

    text_actor = c_camera.get_actor_by_label(label)
    if not text_actor:
        # Rotación mirando desde arriba en Z (-90, 0, 0) para alineación en plano XY
        text_actor = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.TextRenderActor, unreal.Vector(*location), unreal.Rotator(-90, 0, 0))
        if text_actor:
            text_actor.set_actor_label(label)
    else:
        text_actor.set_actor_location_and_rotation(unreal.Vector(*location), unreal.Rotator(-90, 0, 0), False, True)

    if text_actor and hasattr(text_actor, "text_render_component") and text_actor.text_render_component:
        trc = text_actor.text_render_component
        trc.set_text(text)
        trc.set_world_size(world_size)
        trc.set_text_render_color(color)
        trc.set_horizontal_alignment(unreal.HTA_Center)
        trc.set_vertical_alignment(unreal.VTA_Center)
    return text_actor

def spawn_ui_elements(title):
    """Component: Crea elementos 2D XY para niveles de UI con botones coloreados y texto orientado al plano XY."""
    # 1. Fondo UI en el plano XY (Z = -50)
    backdrop_label = "UI_Backdrop_" + title
    mesh_spawner.spawn_mesh(backdrop_label, CUBE_PATH, (0, 0, -50), (32.0, 32.0, 1.0))

    # 2. Cámara 2D XY enfocando desde arriba en Z (0, 0, 1500) mirando hacia abajo (-90, 0, 0)
    cam = c_camera.spawn_or_update_camera("UI_Camera_" + title, (0, 0, 1500), (-90, 0, 0))
    if cam and hasattr(cam, "camera_component") and cam.camera_component:
        cam.camera_component.set_editor_property("projection_mode", unreal.CameraProjectionMode.ORTHOGRAPHIC)
        cam.camera_component.set_editor_property("ortho_width", 2400.0)

    # 3. Luces brillantes en tiempo real
    c_light.setup_directional_light("UI_DirectionalLight_" + title, (0, 0, 1000), (-90, 0, 0), 15.0)
    c_light.setup_sky_light("UI_SkyLight_" + title, (0, 0, 500), 5.0)

    # 4. Botones 2D en el plano XY (coordenadas X, Y)
    if title == "Main":
        mesh_spawner.spawn_mesh("UI_Button_Start", CUBE_PATH, (0, 300, 10), (5.0, 2.0, 0.2))
        spawn_or_update_text_label("UI_Text_Start", "PLAY", (0, 300, 20), world_size=55.0)

        mesh_spawner.spawn_mesh("UI_Button_Settings", CUBE_PATH, (0, 0, 10), (5.0, 2.0, 0.2))
        spawn_or_update_text_label("UI_Text_Settings", "SETTINGS", (0, 0, 20), world_size=45.0)

        mesh_spawner.spawn_mesh("UI_Button_Quit", CUBE_PATH, (0, -300, 10), (5.0, 2.0, 0.2))
        spawn_or_update_text_label("UI_Text_Quit", "QUIT", (0, -300, 20), world_size=55.0)

    elif title == "Settings":
        spawn_or_update_text_label("UI_Text_SettingsTitle", "SETTINGS MENU", (0, 450, 20), world_size=65.0)

        mesh_spawner.spawn_mesh("UI_Button_Volume", CUBE_PATH, (0, 150, 10), (6.0, 2.0, 0.2))
        spawn_or_update_text_label("UI_Text_Volume", "VOLUME: 100%", (0, 150, 20), world_size=40.0)

        mesh_spawner.spawn_mesh("UI_Button_Back", CUBE_PATH, (0, -200, 10), (4.5, 2.0, 0.2))
        spawn_or_update_text_label("UI_Text_Back", "BACK", (0, -200, 20), world_size=50.0)

    elif title == "Victory":
        spawn_or_update_text_label("UI_Text_VictoryTitle", "PROMOTED! (VICTORY)", (0, 450, 20), world_size=65.0, color=unreal.Color(100, 255, 100, 255))

        mesh_spawner.spawn_mesh("UI_Button_Start", CUBE_PATH, (0, 100, 10), (6.0, 2.0, 0.2))
        spawn_or_update_text_label("UI_Text_Restart", "PLAY AGAIN", (0, 100, 20), world_size=45.0)

        mesh_spawner.spawn_mesh("UI_Button_Quit", CUBE_PATH, (0, -200, 10), (5.0, 2.0, 0.2))
        spawn_or_update_text_label("UI_Text_Quit", "MAIN MENU", (0, -200, 20), world_size=40.0)

    elif title == "Defeat":
        spawn_or_update_text_label("UI_Text_DefeatTitle", "YOU'RE FIRED!", (0, 450, 20), world_size=70.0, color=unreal.Color(255, 60, 60, 255))

        mesh_spawner.spawn_mesh("UI_Button_Start", CUBE_PATH, (0, 100, 10), (5.0, 2.0, 0.2))
        spawn_or_update_text_label("UI_Text_Restart", "RETRY", (0, 100, 20), world_size=50.0)

        mesh_spawner.spawn_mesh("UI_Button_Quit", CUBE_PATH, (0, -200, 10), (5.0, 2.0, 0.2))
        spawn_or_update_text_label("UI_Text_Quit", "MAIN MENU", (0, -200, 20), world_size=40.0)
