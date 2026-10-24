# ============================================================
# YOU'RE FIRED - View: Weapon (MVC View)
# ============================================================
import unreal
import level_builder_util as utils

def spawn_weapon(name="Weapon_PaperAirplane", position=(200, 200, 50)):
    unreal.log("[WeaponView] Generando Weapon (Office Supply)...")
    return utils.spawn_actor_by_class_path(
        name,
        "/Script/YoureFired.WeaponBase",
        utils.CONE_PATH,
        position,
        (0.4, 0.4, 0.4)
    )
