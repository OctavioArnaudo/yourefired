# ============================================================
# YOU'RE FIRED - Generador Piso 1: Contabilidad
# ============================================================

import unreal
import level_builder_utils as utils

LEVEL_PATH = "/Game/Generated/Lvl_Piso1_Contabilidad"

def generate_contabilidad():
    utils.log("Generando Piso 1: Contabilidad...")

    unreal.EditorAssetLibrary.make_directory("/Game/Generated")
    if not unreal.EditorLevelLibrary.new_level(LEVEL_PATH):
        utils.log("Error creando el nivel Piso 1.")
        return

    # Perímetro
    utils.build_office_perimeter(floor_size=28.0, wall_height=3.0)

    # Cubículos amplios (Contabilidad)
    desks = [(-500, 500, 0), (500, 500, 0), (-500, -500, 0), (500, -500, 0)]
    for idx, pos in enumerate(desks):
        utils.build_cubicle("Accountant_Desk_{:02d}".format(idx + 1), pos, size_x=2.5)

    # Jugador
    utils.spawn_actor_by_class_path("Player_Worker", "/Script/YoureFired.WorkerCharacter", utils.SPHERE_PATH, (0, -1000, 100))

    # Enemigo suave (1 Coworker)
    utils.spawn_actor_by_class_path("Coworker_Contador", "/Script/YoureFired.CoworkerEnemy", utils.CYLINDER_PATH, (500, 0, 75))

    # 3 Firmas de Contabilidad
    sig_positions = [(-500, 500, 60), (500, -500, 60), (0, 600, 60)]
    for idx, pos in enumerate(sig_positions):
        utils.spawn_actor_by_class_path("Signature_Contabilidad_{:02d}".format(idx + 1), "/Script/YoureFired.SignaturePickup", utils.CUBE_PATH, pos)

    # Café de recarga
    utils.spawn_actor_by_class_path("Coffee_Breakroom", "/Script/YoureFired.CoffeePickup", utils.CYLINDER_PATH, (0, 0, 60))

    # Puerta de salida
    utils.spawn_actor_by_class_path("Exit_To_Marketing", "/Script/YoureFired.OfficeDoor", utils.CUBE_PATH, (0, 1300, 100))

    utils.setup_lighting_and_camera(camera_height=2400.0)

    if unreal.EditorLevelLibrary.save_current_level():
        utils.log("Piso 1: Contabilidad generado exitosamente.")

generate_contabilidad()
