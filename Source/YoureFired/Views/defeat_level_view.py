# ============================================================
# YOU'RE FIRED - View: Defeat UI Level (Lvl_Defeat) - MVC View
# ============================================================
import unreal
import level_builder_util as utils

LEVEL_PATH = "/Game/YoureFired/Levels/Lvl_Defeat"

def build_defeat_level():
    utils.open_or_create_level(LEVEL_PATH)

    mesh = unreal.EditorAssetLibrary.load_asset("/Engine/BasicShapes/Plane.Plane")
    if not mesh:
        mesh = unreal.EditorAssetLibrary.load_asset("/Engine/BasicShapes/Cube.Cube")

    if mesh:
        bg = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.StaticMeshActor, unreal.Vector(0, 0, 0), unreal.Rotator(0, 0, 0))
        bg.set_actor_label("UI_Background_Defeat")
        bg.static_mesh_component.set_static_mesh(mesh)
        bg.set_actor_scale3d(unreal.Vector(25.0, 25.0, 1.0))

    camera = unreal.EditorLevelLibrary.spawn_actor_from_class(
        unreal.CameraActor,
        unreal.Vector(0, -1000, 300),
        unreal.Rotator(-15, 90, 0)
    )
    if camera:
        camera.set_actor_label("UI_DefeatCamera")

    unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.DirectionalLight, unreal.Vector(0, 0, 1000), unreal.Rotator(-45, 0, 0))

    unreal.EditorLevelLibrary.save_current_level()
    unreal.log("[DefeatLevelView] Lvl_Defeat (UI Defeat / You're Fired) generado/cargado correctamente.")

if __name__ == "__main__":
    build_defeat_level()
