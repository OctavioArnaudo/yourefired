# ============================================================
# YOU'RE FIRED - View: Hybrid Player (MVC View)
# ============================================================
import unreal
import level_builder_util as utils

def spawn_hybrid_player(name="HybridPlayer", position=(0, 0, 100)):
    unreal.log("[HybridPlayerView] Generando Hybrid Player...")
    return utils.spawn_actor_by_class_path(
        name,
        "/Script/YoureFired.HybridPlayerModel",
        utils.SPHERE_PATH,
        position,
        (0.8, 0.8, 1.0)
    )
