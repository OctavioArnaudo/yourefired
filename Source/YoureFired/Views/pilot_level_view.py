# ============================================================
# YOU'RE FIRED - View: Pilot Level (Lvl_Pilot) - MVC Architecture
# ============================================================

import unreal

LEVEL_PATH = "/Game/Generated/Lvl_Pilot"

CUBE_PATH = "/Engine/BasicShapes/Cube.Cube"
SPHERE_PATH = "/Engine/BasicShapes/Sphere.Sphere"
CYLINDER_PATH = "/Engine/BasicShapes/Cylinder.Cylinder"
CONE_PATH = "/Engine/BasicShapes/Cone.Cone"

def log(message):
    unreal.log("[PilotLevelView] " + str(message))

def spawn_mesh(name, mesh_path, position, scale=(1, 1, 1), rotation=None):
    if rotation is None:
        rotation = unreal.Rotator(0, 0, 0)
    mesh = unreal.EditorAssetLibrary.load_asset(mesh_path)
    if not mesh:
        return None
    actor = unreal.EditorLevelLibrary.spawn_actor_from_class(
        unreal.StaticMeshActor,
        unreal.Vector(*position),
        rotation
    )
    if actor:
        actor.set_actor_label(name)
        actor.set_actor_scale3d(unreal.Vector(*scale))
        actor.static_mesh_component.set_static_mesh(mesh)
    return actor

def spawn_actor(name, class_path, fallback_mesh, position, scale=(1, 1, 1)):
    actor_class = unreal.load_class(None, class_path)
    if actor_class:
        actor = unreal.EditorLevelLibrary.spawn_actor_from_class(
            actor_class,
            unreal.Vector(*position),
            unreal.Rotator(0, 0, 0)
        )
        if actor:
            actor.set_actor_label(name)
            return actor
    return spawn_mesh(name, fallback_mesh, position, scale)

def build_pilot_level():
    log("Construyendo Lvl_Pilot (Pilot Level Gameplay Scene)...")

    unreal.EditorAssetLibrary.make_directory("/Game/Generated")
    created = unreal.EditorLevelLibrary.new_level(LEVEL_PATH)
    if not created:
        log("No se pudo crear Lvl_Pilot.")
        return

    # 1. Main Level / Floor Layout
    spawn_mesh("Pilot_Floor", CUBE_PATH, (0, 0, -50), (35.0, 35.0, 1.0))
    spawn_mesh("Wall_N", CUBE_PATH, (0, 1750, 100), (1.0, 35.0, 3.0))
    spawn_mesh("Wall_S", CUBE_PATH, (0, -1750, 100), (1.0, 35.0, 3.0))
    spawn_mesh("Wall_E", CUBE_PATH, (1750, 0, 100), (35.0, 1.0, 3.0))
    spawn_mesh("Wall_W", CUBE_PATH, (-1750, 0, 100), (35.0, 1.0, 3.0))

    # 2. Hybrid Player (HybridPlayerModel / Walk / Run / Inventory)
    spawn_actor("HybridPlayer_Hero", "/Script/YoureFired.HybridPlayerModel", SPHERE_PATH, (0, -1200, 100), (0.8, 0.8, 1.0))

    # 3. Enemies (MeleeEnemy, RangeEnemy, HybridEnemy)
    spawn_actor("MeleeEnemy_Coworker", "/Script/YoureFired.CoworkerEnemy", CYLINDER_PATH, (-600, 400, 75), (0.7, 0.7, 0.9))
    spawn_actor("RangeEnemy_Supervisor", "/Script/YoureFired.SupervisorEnemy", CONE_PATH, (600, 400, 75), (0.8, 0.8, 1.2))
    spawn_actor("HybridEnemy_HR", "/Script/YoureFired.SupervisorEnemy", CUBE_PATH, (0, 800, 75), (0.9, 0.9, 1.1))

    # 4. Weapons & Projectiles
    spawn_actor("OfficeWeapon_PaperAirplane", "/Script/YoureFired.WeaponBase", CONE_PATH, (-300, -800, 50), (0.4, 0.4, 0.4))

    # 5. Pickups (CoffeePickup, SignaturePickup)
    spawn_actor("Coffee_Item", "/Script/YoureFired.CoffeePickup", CYLINDER_PATH, (300, -800, 60), (0.3, 0.3, 0.3))
    spawn_actor("Signature_Item", "/Script/YoureFired.SignaturePickup", CUBE_PATH, (0, -600, 60), (0.4, 0.3, 0.05))

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
        log("Lvl_Pilot generado y guardado exitosamente en: " + LEVEL_PATH)

build_pilot_level()
