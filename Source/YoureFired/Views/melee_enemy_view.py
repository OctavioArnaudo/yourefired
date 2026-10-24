# ============================================================
# YOU'RE FIRED - View: Melee Enemy (MVC View)
# ============================================================
import unreal
import level_builder_util as utils

def spawn_melee_enemy(name="MeleeEnemy", position=(500, 500, 75)):
    unreal.log("[MeleeEnemyView] Generando Melee Enemy (Coworker)...")
    return utils.spawn_actor_by_class_path(
        name,
        "/Script/YoureFired.CoworkerEnemy",
        utils.CYLINDER_PATH,
        position,
        (0.7, 0.7, 0.9)
    )
