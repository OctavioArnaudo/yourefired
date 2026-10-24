# ============================================================
# YOU'RE FIRED - View: Range Enemy (MVC View)
# ============================================================
import unreal
import level_builder_util as utils

def spawn_range_enemy(name="RangeEnemy", position=(-500, 500, 75)):
    unreal.log("[RangeEnemyView] Generando Range Enemy (Supervisor)...")
    return utils.spawn_actor_by_class_path(
        name,
        "/Script/YoureFired.SupervisorEnemy",
        utils.CONE_PATH,
        position,
        (0.8, 0.8, 1.2)
    )
