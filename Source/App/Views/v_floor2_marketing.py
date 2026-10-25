# ============================================================
# YOU'RE FIRED - Generador Piso 2: Marketing
# ============================================================

import unreal
import level_builder_utils as utils

LEVEL_PATH = "/Game/Generated/Lvl_Piso2_Marketing"

def generate_marketing():
    utils.log("Generando Piso 2: Marketing...")

    unreal.EditorAssetLibrary.make_directory("/Game/Generated")
    if not unreal.EditorLevelLibrary.new_level(LEVEL_PATH):
        utils.log("Error creando el nivel Piso 2.")
        return

    # Perímetro amplio
    utils.build_office_perimeter(floor_size=32.0, wall_height=3.0)

    # Cubículos abiertos y desordenados
    desks = [(-700, 700, 0), (700, 700, 0), (-700, 0, 0), (700, 0, 0), (0, -600, 0)]
    for idx, pos in enumerate(desks):
        utils.build_cubicle("Designer_Desk_{:02d}".format(idx + 1), pos, size_x=1.8)

    # Jugador
    utils.spawn_actor_by_class_path("Player_Worker", "/Script/YoureFired.WorkerCharacter", utils.SPHERE_PATH, (0, -1200, 100))

    # Enemigos: Diseñadores estresados + 1 Supervisor
    utils.spawn_actor_by_class_path("Designer_1", "/Script/YoureFired.CoworkerEnemy", utils.CYLINDER_PATH, (-700, 300, 75))
    utils.spawn_actor_by_class_path("Designer_2", "/Script/YoureFired.CoworkerEnemy", utils.CYLINDER_PATH, (700, 300, 75))
    utils.spawn_actor_by_class_path("Supervisor_Marketing", "/Script/YoureFired.SupervisorEnemy", utils.CONE_PATH, (0, 200, 75))

    # Firmas
    sig_positions = [(-700, 700, 60), (700, 0, 60), (0, -600, 60)]
    for idx, pos in enumerate(sig_positions):
        utils.spawn_actor_by_class_path("Signature_Marketing_{:02d}".format(idx + 1), "/Script/YoureFired.SignaturePickup", utils.CUBE_PATH, pos)

    # Café
    utils.spawn_actor_by_class_path("Coffee_Marketing_1", "/Script/YoureFired.CoffeePickup", utils.CYLINDER_PATH, (-400, -200, 60))
    utils.spawn_actor_by_class_path("Coffee_Marketing_2", "/Script/YoureFired.CoffeePickup", utils.CYLINDER_PATH, (400, -200, 60))

    # Puerta de salida
    utils.spawn_actor_by_class_path("Exit_To_RRHH", "/Script/YoureFired.OfficeDoor", utils.CUBE_PATH, (0, 1500, 100))

    utils.setup_lighting_and_camera(camera_height=2600.0)

    if unreal.EditorLevelLibrary.save_current_level():
        utils.log("Piso 2: Marketing generado exitosamente.")

generate_marketing()
