# ============================================================
# YOU'RE FIRED - View: Defeat / Game Over Level (Lvl_Defeat) - MVC
# ============================================================

import unreal

LEVEL_PATH = "/Game/YoureFired/Levels/Lvl_Defeat"

def build_defeat_level():
    unreal.EditorAssetLibrary.make_directory("/Game/YoureFired/Levels")
    unreal.EditorLevelLibrary.new_level(LEVEL_PATH)

    # Spawn Pink Slip / Carta de Despido visual prop
    mesh = unreal.EditorAssetLibrary.load_asset("/Engine/BasicShapes/Cube.Cube")
    if mesh:
        slip = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.StaticMeshActor, unreal.Vector(0, 0, 0), unreal.Rotator(0, 0, 0))
        slip.set_actor_label("PinkSlip_Notice")
        slip.static_mesh_component.set_static_mesh(mesh)
        slip.set_actor_scale3d(unreal.Vector(4, 3, 0.1))

    unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.DirectionalLight, unreal.Vector(0, 0, 1000), unreal.Rotator(-45, 0, 0))
    unreal.EditorLevelLibrary.save_current_level()
    unreal.log("[DefeatLevelView] Lvl_Defeat (You're Fired) creado correctamente.")

if __name__ == "__main__":
    build_defeat_level()
