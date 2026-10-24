# ============================================================
# YOU'RE FIRED - View: Office Level Environment Layout (Colorful & Bright)
# ============================================================

import unreal
from Builders import c_spawner

CUBE_PATH = "/Engine/BasicShapes/Cube.Cube"
SPHERE_PATH = "/Engine/BasicShapes/Sphere.Sphere"
CYLINDER_PATH = "/Engine/BasicShapes/Cylinder.Cylinder"
CONE_PATH = "/Engine/BasicShapes/Cone.Cone"

def build_office_layout():
    unreal.log("[OfficeLevel] Construyendo diseño colorido y brillante de la oficina...")

    # 1. Perímetro y suelo
    c_spawner.spawn_mesh("Floor_Main", CUBE_PATH, (0, 0, -50), (32.0, 32.0, 1.0))
    wall_offset = 1600.0
    c_spawner.spawn_mesh("Wall_North", CUBE_PATH, (0, wall_offset, 100), (1.0, 32.0, 3.0))
    c_spawner.spawn_mesh("Wall_South", CUBE_PATH, (0, -wall_offset, 100), (1.0, 32.0, 3.0))
    c_spawner.spawn_mesh("Wall_East", CUBE_PATH, (wall_offset, 0, 100), (32.0, 1.0, 3.0))
    c_spawner.spawn_mesh("Wall_West", CUBE_PATH, (-wall_offset, 0, 100), (32.0, 1.0, 3.0))

    # 2. Cubículos de oficina
    cubicle_positions = [
        (-800, 600, 0),  (800, 600, 0),
        (-800, 0, 0),    (800, 0, 0),
        (-800, -600, 0), (800, -600, 0),
        (0, 400, 0),     (0, -400, 0)
    ]
    for idx, pos in enumerate(cubicle_positions):
        cx, cy, cz = pos
        c_spawner.spawn_mesh(f"Cubicle_{idx+1:02d}_Desk", CUBE_PATH, (cx, cy, cz + 30), (2.0, 1.0, 0.6))
        c_spawner.spawn_mesh(f"Cubicle_{idx+1:02d}_Chair", CYLINDER_PATH, (cx, cy - 60, cz + 30), (0.4, 0.4, 0.6))

    # 3. Jugador y Enemigos
    c_spawner.spawn_actor("Player_Worker", "/Script/YoureFired.WorkerCharacter", (0, -1200, 100))

    coworker_positions = [(-800, 300, 75), (800, -300, 75), (0, 700, 75)]
    for idx, pos in enumerate(coworker_positions):
        c_spawner.spawn_actor(f"Coworker_{idx+1:02d}", "/Script/YoureFired.CoworkerEnemy", pos)

    supervisor_positions = [(-400, -100, 75), (400, 100, 75)]
    for idx, pos in enumerate(supervisor_positions):
        c_spawner.spawn_actor(f"Supervisor_{idx+1:02d}", "/Script/YoureFired.SupervisorEnemy", pos)

    # 4. Pickups y Puerta
    c_spawner.spawn_actor("CoffeeItem", "/Script/YoureFired.CoffeePickup", (300, -800, 60))
    c_spawner.spawn_actor("SignatureItem", "/Script/YoureFired.SignaturePickup", (0, -600, 60))
    c_spawner.spawn_actor("FloorExit_Door", "/Script/YoureFired.OfficeDoor", (0, 1500, 100))

    # 5. Cámara y Luces de alta intensidad para evitar oscuridad
    cam = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.CameraActor, unreal.Vector(0, 0, 2600), unreal.Rotator(-90, 0, 0))
    cam.set_actor_label("Office_TopDownCamera")

    dir_light = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.DirectionalLight, unreal.Vector(0, 0, 1000), unreal.Rotator(-50, -30, 0))
    if dir_light:
        dir_light.light_component.set_editor_property("intensity", 10.0)

    skylight = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.SkyLight, unreal.Vector(0, 0, 500), unreal.Rotator(0, 0, 0))
    if skylight:
        skylight.light_component.set_editor_property("intensity", 2.0)
