# ============================================================
# YOU'RE FIRED - View: Victory Level (Lvl_Victory) - MVC
# ============================================================

import unreal

LEVEL_PATH = "/Game/YoureFired/Levels/Lvl_Victory"

def build_victory_level():
    unreal.EditorAssetLibrary.make_directory("/Game/YoureFired/Levels")
    unreal.EditorLevelLibrary.new_level(LEVEL_PATH)

    # Spawn Victory Podium / Stage
    mesh = unreal.EditorAssetLibrary.load_asset("/Engine/BasicShapes/Cube.Cube")
    if mesh:
        podium = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.StaticMeshActor, unreal.Vector(0, 0, 0), unreal.Rotator(0, 0, 0))
        podium.set_actor_label("Victory_Podium")
        podium.static_mesh_component.set_static_mesh(mesh)
        podium.set_actor_scale3d(unreal.Vector(10, 10, 0.5))

    unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.DirectionalLight, unreal.Vector(0, 0, 1000), unreal.Rotator(-50, 0, 0))
    unreal.EditorLevelLibrary.save_current_level()
    unreal.log("[VictoryLevelView] Lvl_Victory creado correctamente.")

if __name__ == "__main__":
    build_victory_level()
