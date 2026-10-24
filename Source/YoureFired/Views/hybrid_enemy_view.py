# ============================================================
# YOU'RE FIRED - View: Hybrid Enemy (MVC View)
# ============================================================
import unreal
import level_builder_util as utils

def spawn_hybrid_enemy(name="HybridEnemy", position=(0, 600, 75)):
    unreal.log("[HybridEnemyView] Generando Hybrid Enemy (HR Agent)...")
    return utils.spawn_actor_by_class_path(
        name,
        "/Script/YoureFired.SupervisorEnemy",
        utils.CUBE_PATH,
        position,
        (0.9, 0.9, 1.1)
    )
