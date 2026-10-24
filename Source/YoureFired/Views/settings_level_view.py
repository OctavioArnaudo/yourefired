# ============================================================
# YOU'RE FIRED - View: Settings Level (MVC View)
# ============================================================
import unreal

LEVEL_PATH = "/Game/YoureFired/Levels/Lvl_Settings"

def build_settings_level():
    unreal.EditorAssetLibrary.make_directory("/Game/YoureFired/Levels")
    unreal.EditorLevelLibrary.new_level(LEVEL_PATH)

    mesh = unreal.EditorAssetLibrary.load_asset("/Engine/BasicShapes/Cube.Cube")
    if mesh:
        bg = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.StaticMeshActor, unreal.Vector(0, 0, -50), unreal.Rotator(0, 0, 0))
        bg.set_actor_label("Settings_Background")
        bg.static_mesh_component.set_static_mesh(mesh)
        bg.set_actor_scale3d(unreal.Vector(15, 15, 1))

    unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.DirectionalLight, unreal.Vector(0, 0, 1000), unreal.Rotator(-45, 0, 0))
    unreal.EditorLevelLibrary.save_current_level()
    unreal.log("[SettingsLevelView] Lvl_Settings generado correctamente.")

if __name__ == "__main__":
    build_settings_level()
