# ============================================================
# YOU'RE FIRED - Generador Piso 4: La Sala de Juntas (Penthouse)
# ============================================================

import unreal
import level_builder_utils as utils

LEVEL_PATH = "/Game/Generated/Lvl_Piso4_Penthouse"

def generate_penthouse():
    utils.log("Generando Piso 4: La Sala de Juntas (Penthouse - Gran Jefe Final)...")

    unreal.EditorAssetLibrary.make_directory("/Game/Generated")
    if not unreal.EditorLevelLibrary.new_level(LEVEL_PATH):
        utils.log("Error creando el nivel Piso 4.")
        return

    # Perímetro amplio y lujoso de la Sala de Juntas
    utils.build_office_perimeter(floor_size=30.0, wall_height=4.0)

    # Gran Mesa de Conferencia en el centro
    utils.spawn_mesh("Executive_Table", utils.CUBE_PATH, (0, 200, 40), (8.0, 3.0, 0.8))

    # Sillas Ejecutivas
    chairs = [
        ("Chair_Left_1", (-500, 300, 40)),
        ("Chair_Left_2", (-500, 100, 40)),
        ("Chair_Right_1", (500, 300, 40)),
        ("Chair_Right_2", (500, 100, 40)),
        ("CEO_Chair", (0, 600, 40))
    ]
    for name, pos in chairs:
        utils.spawn_mesh(name, utils.CYLINDER_PATH, pos, (0.5, 0.5, 0.8))

    # Jugador al inicio de la sala
    utils.spawn_actor_by_class_path("Player_Worker", "/Script/YoureFired.WorkerCharacter", utils.SPHERE_PATH, (0, -1000, 100))

    # Gran Jefe / CEO (Supervisor Avanzado)
    utils.spawn_actor_by_class_path("Big_Boss_CEO", "/Script/YoureFired.SupervisorEnemy", utils.CONE_PATH, (0, 700, 100), scale=(1.5, 1.5, 2.0))

    # Suministros / Armas de alta calidad antes del jefe
    utils.spawn_actor_by_class_path("Gold_Coffee", "/Script/YoureFired.CoffeePickup", utils.CYLINDER_PATH, (-300, -800, 60))
    utils.spawn_actor_by_class_path("Executive_Stapler", "/Script/YoureFired.WeaponBase", utils.CONE_PATH, (300, -800, 50))

    # Puerta Final
    utils.spawn_actor_by_class_path("Victory_Door", "/Script/YoureFired.OfficeDoor", utils.CUBE_PATH, (0, 1300, 100))

    utils.setup_lighting_and_camera(camera_height=2500.0)

    if unreal.EditorLevelLibrary.save_current_level():
        utils.log("Piso 4: Sala de Juntas generado exitosamente.")

generate_penthouse()
