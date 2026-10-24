# ============================================================
# YOU'RE FIRED - View: Pilot Level (Lvl_Pilot) - MVC Architecture
# ============================================================

import unreal
import level_builder_util as utils

LEVEL_PATH = "/Game/YoureFired/Levels/Lvl_Pilot"

CUBE_PATH = utils.CUBE_PATH
SPHERE_PATH = utils.SPHERE_PATH
CYLINDER_PATH = utils.CYLINDER_PATH
CONE_PATH = utils.CONE_PATH

def log(message):
    unreal.log("[PilotLevelView] " + str(message))

def build_pilot_level():
    log("Construyendo/Cargando Lvl_Pilot (Pilot Level Gameplay Scene)...")

    utils.open_or_create_level(LEVEL_PATH)

    # 1. Main Level / Floor Layout
    utils.spawn_mesh("Pilot_Floor", CUBE_PATH, (0, 0, -50), (35.0, 35.0, 1.0))
    utils.spawn_mesh("Wall_N", CUBE_PATH, (0, 1750, 100), (1.0, 35.0, 3.0))
    utils.spawn_mesh("Wall_S", CUBE_PATH, (0, -1750, 100), (1.0, 35.0, 3.0))
    utils.spawn_mesh("Wall_E", CUBE_PATH, (1750, 0, 100), (35.0, 1.0, 3.0))
    utils.spawn_mesh("Wall_W", CUBE_PATH, (-1750, 0, 100), (35.0, 1.0, 3.0))

    # 2. Hybrid Player (HybridPlayerModel / Walk / Run / Inventory)
    utils.spawn_actor_by_class_path("HybridPlayer_Hero", "/Script/YoureFired.HybridPlayerModel", SPHERE_PATH, (0, -1200, 100), (0.8, 0.8, 1.0))

    # 3. Enemies (MeleeEnemy, RangeEnemy, HybridEnemy)
    utils.spawn_actor_by_class_path("MeleeEnemy_Coworker", "/Script/YoureFired.CoworkerEnemy", CYLINDER_PATH, (-600, 400, 75), (0.7, 0.7, 0.9))
    utils.spawn_actor_by_class_path("RangeEnemy_Supervisor", "/Script/YoureFired.SupervisorEnemy", CONE_PATH, (600, 400, 75), (0.8, 0.8, 1.2))
    utils.spawn_actor_by_class_path("HybridEnemy_HR", "/Script/YoureFired.SupervisorEnemy", CUBE_PATH, (0, 800, 75), (0.9, 0.9, 1.1))

    # 4. Weapons & Projectiles
    utils.spawn_actor_by_class_path("OfficeWeapon_PaperAirplane", "/Script/YoureFired.WeaponBase", CONE_PATH, (-300, -800, 50), (0.4, 0.4, 0.4))

    # 5. Pickups (CoffeePickup, SignaturePickup)
    utils.spawn_actor_by_class_path("Coffee_Item", "/Script/YoureFired.CoffeePickup", CYLINDER_PATH, (300, -800, 60), (0.3, 0.3, 0.3))
    utils.spawn_actor_by_class_path("Signature_Item", "/Script/YoureFired.SignaturePickup", CUBE_PATH, (0, -600, 60), (0.4, 0.3, 0.05))

    # 6. Camera (Top-Down Camera)
    camera = unreal.EditorLevelLibrary.spawn_actor_from_class(
        unreal.CameraActor,
        unreal.Vector(0, 0, 2600),
        unreal.Rotator(-90, 0, 0)
    )
    if camera:
        camera.set_actor_label("Pilot_TopDownCamera")

    # 7. Lighting
    unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.DirectionalLight, unreal.Vector(0, 0, 1000), unreal.Rotator(-50, -30, 0))
    unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.SkyLight, unreal.Vector(0, 0, 500), unreal.Rotator(0, 0, 0))

    # Save level
    if unreal.EditorLevelLibrary.save_current_level():
        log("Lvl_Pilot guardado exitosamente en: " + LEVEL_PATH)

if __name__ == "__main__":
    build_pilot_level()
