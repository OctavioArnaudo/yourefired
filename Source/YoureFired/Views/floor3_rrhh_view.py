# ============================================================
# YOU'RE FIRED - Generador Piso 3: Recursos Humanos
# ============================================================

import unreal
import level_builder_utils as utils

LEVEL_PATH = "/Game/Generated/Lvl_Piso3_RRHH"

def generate_rrhh():
    utils.log("Generando Piso 3: Recursos Humanos (Laberinto Estrecho)...")

    unreal.EditorAssetLibrary.make_directory("/Game/Generated")
    if not unreal.EditorLevelLibrary.new_level(LEVEL_PATH):
        utils.log("Error creando el nivel Piso 3.")
        return

    # Perímetro
    utils.build_office_perimeter(floor_size=36.0, wall_height=3.5)

    # Paredes internas formando laberinto
    maze_walls = [
        ("MazeWall_1", (0, 400, 100), (12.0, 0.2, 3.0)),
        ("MazeWall_2", (-600, -200, 100), (0.2, 12.0, 3.0)),
        ("MazeWall_3", (600, -200, 100), (0.2, 12.0, 3.0)),
        ("MazeWall_4", (0, -800, 100), (16.0, 0.2, 3.0)),
    ]
    for name, pos, scale in maze_walls:
        utils.spawn_mesh(name, utils.CUBE_PATH, pos, scale)

    # Jugador
    utils.spawn_actor_by_class_path("Player_Worker", "/Script/YoureFired.WorkerCharacter", utils.SPHERE_PATH, (0, -1500, 100))

    # Enemigos: Múltiples Supervisores patrullando
    supervisors = [
        ("Supervisor_RRHH_1", (-900, 0, 75)),
        ("Supervisor_RRHH_2", (900, 0, 75)),
        ("Supervisor_RRHH_3", (0, 800, 75))
    ]
    for name, pos in supervisors:
        utils.spawn_actor_by_class_path(name, "/Script/YoureFired.SupervisorEnemy", utils.CONE_PATH, pos)

    # Firmas difíciles
    sig_positions = [(-1200, 1000, 60), (1200, 1000, 60), (0, -200, 60)]
    for idx, pos in enumerate(sig_positions):
        utils.spawn_actor_by_class_path("Signature_RRHH_{:02d}".format(idx + 1), "/Script/YoureFired.SignaturePickup", utils.CUBE_PATH, pos)

    # Tazas de café escasas
    utils.spawn_actor_by_class_path("Coffee_RRHH", "/Script/YoureFired.CoffeePickup", utils.CYLINDER_PATH, (0, 1000, 60))

    # Puerta al Penthouse
    utils.spawn_actor_by_class_path("Exit_To_Penthouse", "/Script/YoureFired.OfficeDoor", utils.CUBE_PATH, (0, 1700, 100))

    utils.setup_lighting_and_camera(camera_height=2800.0)

    if unreal.EditorLevelLibrary.save_current_level():
        utils.log("Piso 3: Recursos Humanos generado exitosamente.")

generate_rrhh()
