# ============================================================
# YOU'RE FIRED - View: Signature Pickup (MVC View)
# ============================================================
import unreal
import level_builder_util as utils

def spawn_signature_pickup(name="SignaturePickup", position=(0, -400, 60)):
    unreal.log("[SignaturePickupView] Generando Approval Signature Pickup...")
    return utils.spawn_actor_by_class_path(
        name,
        "/Script/YoureFired.SignaturePickup",
        utils.CUBE_PATH,
        position,
        (0.4, 0.3, 0.05)
    )
