# ============================================================
# YOU'RE FIRED - Controller: Environment Lighting, Camera & 3D UI
# ============================================================
import unreal
import c_sm_spawner as mesh_spawner
import c_camera
import c_light

CUBE_PATH = "/Engine/BasicShapes/Cube.Cube"

def spawn_or_update_text_label(label, text, location, world_size=40.0, color=None):
    """Component: Spawnea o reutiliza un TextRenderActor para mostrar texto 3D nítido en los botones UI."""
    if color is None:
        color = unreal.Color(255, 255, 255, 255)

    text_actor = c_camera.get_actor_by_label(label)
    if not text_actor:
        text_actor = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.TextRenderActor, unreal.Vector(*location), unreal.Rotator(0, -90, 0))
        if text_actor:
            text_actor.set_actor_label(label)
    else:
        text_actor.set_actor_location_and_rotation(unreal.Vector(*location), unreal.Rotator(0, -90, 0), False, True)

    if text_actor and hasattr(text_actor, "text_render_component") and text_actor.text_render_component:
        trc = text_actor.text_render_component
        trc.set_text(text)
        trc.set_world_size(world_size)
        trc.set_text_render_color(color)
        trc.set_horizontal_alignment(unreal.HTA_Center)
        trc.set_vertical_alignment(unreal.VTA_Center)
    return text_actor

def spawn_ui_elements(title):
    """Component: Crea elementos base e interactivos para niveles de UI con botones 3D coloreados y texto legible."""
    # 1. Fondo UI (Azul Real)
    backdrop_label = "UI_Backdrop_" + title
    mesh_spawner.spawn_mesh(backdrop_label, CUBE_PATH, (0, 800, 0), (0.5, 30.0, 20.0))

    # 2. Cámara UI enfocando al frente
    c_camera.spawn_or_update_camera("UI_Camera_" + title, (0, 0, 100), (0, 0, 0))

    # 3. Luces brillantes en tiempo real
    c_light.setup_directional_light("UI_DirectionalLight_" + title, (0, 200, 500), (-45, -90, 0), 15.0)
    c_light.setup_sky_light("UI_SkyLight_" + title, (0, 200, 300), 5.0)

    # 4. Botones 3D coloreados con etiquetas de texto en tiempo real
    if title == "Main":
        mesh_spawner.spawn_mesh("UI_Button_Start", CUBE_PATH, (-200, 750, 150), (0.2, 3.5, 1.2))
        spawn_or_update_text_label("UI_Text_Start", "PLAY", (-190, 750, 150), world_size=45.0)

        mesh_spawner.spawn_mesh("UI_Button_Settings", CUBE_PATH, (-200, 750, 0), (0.2, 3.5, 1.2))
        spawn_or_update_text_label("UI_Text_Settings", "SETTINGS", (-190, 750, 0), world_size=38.0)

        mesh_spawner.spawn_mesh("UI_Button_Quit", CUBE_PATH, (-200, 750, -150), (0.2, 3.5, 1.2))
        spawn_or_update_text_label("UI_Text_Quit", "QUIT", (-190, 750, -150), world_size=45.0)

    elif title == "Settings":
        spawn_or_update_text_label("UI_Text_SettingsTitle", "SETTINGS MENU", (-190, 750, 220), world_size=50.0)

        mesh_spawner.spawn_mesh("UI_Button_Volume", CUBE_PATH, (-200, 750, 80), (0.2, 4.0, 1.0))
        spawn_or_update_text_label("UI_Text_Volume", "VOLUME: 100%", (-190, 750, 80), world_size=35.0)

        mesh_spawner.spawn_mesh("UI_Button_Back", CUBE_PATH, (-200, 750, -100), (0.2, 3.0, 1.0))
        spawn_or_update_text_label("UI_Text_Back", "BACK", (-190, 750, -100), world_size=40.0)

    elif title == "Victory":
        spawn_or_update_text_label("UI_Text_VictoryTitle", "PROMOTED! (VICTORY)", (-190, 750, 220), world_size=50.0, color=unreal.Color(100, 255, 100, 255))

        mesh_spawner.spawn_mesh("UI_Button_Start", CUBE_PATH, (-200, 750, 50), (0.2, 4.0, 1.2))
        spawn_or_update_text_label("UI_Text_Restart", "PLAY AGAIN", (-190, 750, 50), world_size=40.0)

        mesh_spawner.spawn_mesh("UI_Button_Quit", CUBE_PATH, (-200, 750, -100), (0.2, 3.0, 1.0))
        spawn_or_update_text_label("UI_Text_Quit", "MAIN MENU", (-190, 750, -100), world_size=35.0)

    elif title == "Defeat":
        spawn_or_update_text_label("UI_Text_DefeatTitle", "YOU'RE FIRED!", (-190, 750, 220), world_size=55.0, color=unreal.Color(255, 60, 60, 255))

        mesh_spawner.spawn_mesh("UI_Button_Start", CUBE_PATH, (-200, 750, 50), (0.2, 4.0, 1.2))
        spawn_or_update_text_label("UI_Text_Restart", "RETRY", (-190, 750, 50), world_size=40.0)

        mesh_spawner.spawn_mesh("UI_Button_Quit", CUBE_PATH, (-200, 750, -100), (0.2, 3.0, 1.0))
        spawn_or_update_text_label("UI_Text_Quit", "MAIN MENU", (-190, 750, -100), world_size=35.0)
