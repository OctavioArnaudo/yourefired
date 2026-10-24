# ============================================================
# YOU'RE FIRED - View: Coffee Pickup (MVC View)
# ============================================================
import unreal
import level_builder_util as utils

def spawn_coffee_pickup(name="CoffeePickup", position=(-200, 200, 60)):
    unreal.log("[CoffeePickupView] Generando Coffee Pickup...")
    return utils.spawn_actor_by_class_path(
        name,
        "/Script/YoureFired.CoffeePickup",
        utils.CYLINDER_PATH,
        position,
        (0.3, 0.3, 0.3)
    )
