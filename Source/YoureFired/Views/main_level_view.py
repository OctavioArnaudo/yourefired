# ============================================================
# YOU'RE FIRED - View: Main Level / Main Menu (MVC View)
# ============================================================
import unreal

LEVEL_PATH = "/Game/YoureFired/Levels/Lvl_Main"

def build_main_level():
    unreal.EditorAssetLibrary.make_directory("/Game/YoureFired/Levels")
    unreal.EditorLevelLibrary.new_level(LEVEL_PATH)

    mesh = unreal.EditorAssetLibrary.load_asset("/Engine/BasicShapes/Cube.Cube")
    if mesh:
        bg = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.StaticMeshActor, unreal.Vector(0, 0, -50), unreal.Rotator(0, 0, 0))
        bg.set_actor_label("MainMenu_Background")
        bg.static_mesh_component.set_static_mesh(mesh)
        bg.set_actor_scale3d(unreal.Vector(20, 20, 1))

    unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.DirectionalLight, unreal.Vector(0, 0, 1000), unreal.Rotator(-45, 0, 0))
    unreal.EditorLevelLibrary.save_current_level()
    unreal.log("[MainLevelView] Lvl_Main generado correctamente.")

if __name__ == "__main__":
    build_main_level()
