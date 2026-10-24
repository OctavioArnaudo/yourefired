# ============================================================
# YOU'RE FIRED - Generador de Nivel Principal de Prueba (Gameplay Test Level)
# ============================================================

import unreal
import level_builder_utils as utils

LEVEL_PATH = "/Game/Generated/Lvl_OfficeFloorTest"

def generate_office_level():
    utils.log("Iniciando generacion del mapa de prueba You're Fired...")

    # Crear carpeta de destino
    unreal.EditorAssetLibrary.make_directory("/Game/Generated")

    # Crear nivel nuevo
    created = unreal.EditorLevelLibrary.new_level(LEVEL_PATH)
    if not created:
        utils.log("No se pudo crear el nivel en " + LEVEL_PATH)
        return

    # 1. Estructura del Piso de Oficina
    utils.build_office_perimeter(floor_size=32.0, wall_height=3.0)

    # 2. Cubículos de Oficina (Laberinto)
    cubicle_positions = [
        (-800, 600, 0),  (800, 600, 0),
        (-800, 0, 0),    (800, 0, 0),
        (-800, -600, 0), (800, -600, 0),
        (0, 400, 0),     (0, -400, 0)
    ]
    for idx, pos in enumerate(cubicle_positions):
        utils.build_cubicle("Cubicle_{:02d}".format(idx + 1), pos)

    # 3. Jugador (WorkerCharacter)
    utils.spawn_actor_by_class_path(
        "Player_Worker",
        "/Script/YoureFired.WorkerCharacter",
        utils.SPHERE_PATH,
        (0, -1200, 100),
        (0.8, 0.8, 1.0)
    )

    # 4. Enemigos - Compañeros Tóxicos (CoworkerEnemy)
    coworker_positions = [
        (-800, 300, 75),
        (800, -300, 75),
        (0, 700, 75)
    ]
    for idx, pos in enumerate(coworker_positions):
        utils.spawn_actor_by_class_path(
            "Coworker_{:02d}".format(idx + 1),
            "/Script/YoureFired.CoworkerEnemy",
            utils.CYLINDER_PATH,
            pos,
            (0.7, 0.7, 0.9)
        )

    # 5. Enemigos - Supervisores Patrulleros (SupervisorEnemy)
    supervisor_positions = [
        (-400, -100, 75),
        (400, 100, 75)
    ]
    for idx, pos in enumerate(supervisor_positions):
        utils.spawn_actor_by_class_path(
            "Supervisor_{:02d}".format(idx + 1),
            "/Script/YoureFired.SupervisorEnemy",
            utils.CONE_PATH,
            pos,
            (0.8, 0.8, 1.2)
        )

    # 6. Pickups - Tazas de Café (CoffeePickup)
    coffee_positions = [
        (-800, 600, 60),
        (800, -600, 60),
        (0, -400, 60)
    ]
    for idx, pos in enumerate(coffee_positions):
        utils.spawn_actor_by_class_path(
            "CoffeePickup_{:02d}".format(idx + 1),
            "/Script/YoureFired.CoffeePickup",
            utils.CYLINDER_PATH,
            pos,
            (0.3, 0.3, 0.3)
        )

    # 7. Pickups - Firmas de Aprobación (SignaturePickup)
    signature_positions = [
        (-800, -600, 60),
        (800, 600, 60),
        (0, 400, 60)
    ]
    for idx, pos in enumerate(signature_positions):
        utils.spawn_actor_by_class_path(
            "SignaturePickup_{:02d}".format(idx + 1),
            "/Script/YoureFired.SignaturePickup",
            utils.CUBE_PATH,
            pos,
            (0.4, 0.3, 0.05)
        )

    # 8. Suministros de Oficina / Armas (WeaponBase)
    weapon_positions = [
        (-200, -800, 50),
        (200, -800, 50),
        (-300, 300, 50),
        (300, 300, 50)
    ]
    for idx, pos in enumerate(weapon_positions):
        utils.spawn_actor_by_class_path(
            "OfficeWeapon_{:02d}".format(idx + 1),
            "/Script/YoureFired.WeaponBase",
            utils.CONE_PATH,
            pos,
            (0.4, 0.4, 0.4)
        )

    # 9. Puerta de Salida del Piso (OfficeDoor)
    utils.spawn_actor_by_class_path(
        "FloorExit_Door",
        "/Script/YoureFired.OfficeDoor",
        utils.CUBE_PATH,
        (0, 1500, 100),
        (1.5, 0.3, 2.0)
    )

    # 10. Iluminación y Cámara Top-Down
    utils.setup_lighting_and_camera(camera_height=2600.0)

    # Guardar nivel
    saved = unreal.EditorLevelLibrary.save_current_level()
    if saved:
        utils.log("Nivel guardado exitosamente en: " + LEVEL_PATH)
    else:
        utils.log("Error al guardar el nivel.")

# Ejecución
generate_office_level()
