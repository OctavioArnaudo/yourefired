# ============================================================
# YOU'RE FIRED - View: Pilot Level (Lvl_Pilot) - MVC Architecture
# ============================================================

import unreal
from Builders import s_level, c_spawner

LEVEL_PATH = "/Game/YoureFired/Levels/Lvl_Pilot"
GM_PATH = "/Game/TopDown/Blueprints/PilotLevelGM.PilotLevelGM_C"

CUBE_PATH = "/Engine/BasicShapes/Cube.Cube"
SPHERE_PATH = "/Engine/BasicShapes/Sphere.Sphere"
CYLINDER_PATH = "/Engine/BasicShapes/Cylinder.Cylinder"
CONE_PATH = "/Engine/BasicShapes/Cone.Cone"

def log(message):
    unreal.log("[PilotLevelView] " + str(message))

def build_pilot_level():
    log("Construyendo/Cargando Lvl_Pilot (Pilot Level Gameplay Scene)...")

    s_level.initialize_level(LEVEL_PATH, GM_PATH)

    # 1. Main Level / Floor Layout
    c_spawner.spawn_mesh("Pilot_Floor", CUBE_PATH, (0, 0, -50), (35.0, 35.0, 1.0))
    c_spawner.spawn_mesh("Wall_N", CUBE_PATH, (0, 1750, 100), (1.0, 35.0, 3.0))
    c_spawner.spawn_mesh("Wall_S", CUBE_PATH, (0, -1750, 100), (1.0, 35.0, 3.0))
    c_spawner.spawn_mesh("Wall_E", CUBE_PATH, (1750, 0, 100), (35.0, 1.0, 3.0))
    c_spawner.spawn_mesh("Wall_W", CUBE_PATH, (-1750, 0, 100), (35.0, 1.0, 3.0))

    # 2. Hybrid Player
    c_spawner.spawn_actor("HybridPlayer_Hero", "/Script/YoureFired.HybridPlayerModel", (0, -1200, 100))

    # 3. Enemies
    c_spawner.spawn_actor("MeleeEnemy_Coworker", "/Script/YoureFired.CoworkerEnemy", (-600, 400, 75))
    c_spawner.spawn_actor("RangeEnemy_Supervisor", "/Script/YoureFired.SupervisorEnemy", (600, 400, 75))
    c_spawner.spawn_actor("HybridEnemy_HR", "/Script/YoureFired.SupervisorEnemy", (0, 800, 75))

    # 4. Weapons & Pickups
    c_spawner.spawn_actor("OfficeWeapon_PaperAirplane", "/Script/YoureFired.WeaponBase", (-300, -800, 50))
    c_spawner.spawn_actor("Coffee_Item", "/Script/YoureFired.CoffeePickup", (300, -800, 60))
    c_spawner.spawn_actor("Signature_Item", "/Script/YoureFired.SignaturePickup", (0, -600, 60))

    # 5. Camera & Lighting
    camera = unreal.EditorLevelLibrary.spawn_actor_from_class(
        unreal.CameraActor,
        unreal.Vector(0, 0, 2600),
        unreal.Rotator(-90, 0, 0)
    )
    if camera:
        camera.set_actor_label("Pilot_TopDownCamera")

    unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.DirectionalLight, unreal.Vector(0, 0, 1000), unreal.Rotator(-50, -30, 0))
    unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.SkyLight, unreal.Vector(0, 0, 500), unreal.Rotator(0, 0, 0))

    if unreal.EditorLevelLibrary.save_current_level():
        log("Lvl_Pilot guardado exitosamente en: " + LEVEL_PATH)

if __name__ == "__main__":
    build_pilot_level()
