# ============================================================
# YOU'RE FIRED - Level Builder Utility Library (Unreal Python)
# ============================================================

import unreal

# Shapes Primitivas de Unreal Engine
CUBE_PATH = "/Engine/BasicShapes/Cube.Cube"
SPHERE_PATH = "/Engine/BasicShapes/Sphere.Sphere"
CYLINDER_PATH = "/Engine/BasicShapes/Cylinder.Cylinder"
CONE_PATH = "/Engine/BasicShapes/Cone.Cone"

def log(message):
    unreal.log("[YoureFiredBuilder] " + str(message))

def spawn_mesh(name, mesh_path, position, scale=(1, 1, 1), rotation=None):
    """Spawnea un StaticMeshActor con la malla especificada"""
    if rotation is None:
        rotation = unreal.Rotator(0, 0, 0)

    mesh = unreal.EditorAssetLibrary.load_asset(mesh_path)
    if not mesh:
        log("ERROR: No se pudo cargar " + mesh_path)
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

def spawn_actor_by_class_path(name, class_path, fallback_mesh_path, position, scale=(1, 1, 1), rotation=None):
    """Intenta spawnear la clase C++/BP del juego, y si no existe usa la malla de respaldo"""
    if rotation is None:
        rotation = unreal.Rotator(0, 0, 0)

    actor_class = unreal.load_class(None, class_path)
    if actor_class:
        actor = unreal.EditorLevelLibrary.spawn_actor_from_class(
            actor_class,
            unreal.Vector(*position),
            rotation
        )
        if actor:
            actor.set_actor_label(name)
            log("Spawneado Actor C++: " + name + " (" + class_path + ")")
            return actor

    log("Aviso: No se encontro " + class_path + ". Usando fallback mesh: " + fallback_mesh_path)
    return spawn_mesh(name, fallback_mesh_path, position, scale, rotation)

def build_office_perimeter(floor_size=30.0, wall_height=3.0):
    """Construye el suelo y las 4 paredes perimetrales de la oficina"""
    log("Generando suelo y paredes perimetrales...")

    # Suelo Principal
    spawn_mesh(
        "Floor_Main",
        CUBE_PATH,
        (0, 0, -50),
        (floor_size, floor_size, 1)
    )

    wall_offset = floor_size * 50.0
    wall_scale_x = (1, floor_size, wall_height)
    wall_scale_y = (floor_size, 1, wall_height)

    # Paredes Perimetrales
    spawn_mesh("Wall_North", CUBE_PATH, (0, wall_offset, 100), wall_scale_x)
    spawn_mesh("Wall_South", CUBE_PATH, (0, -wall_offset, 100), wall_scale_x)
    spawn_mesh("Wall_East", CUBE_PATH, (wall_offset, 0, 100), wall_scale_y)
    spawn_mesh("Wall_West", CUBE_PATH, (-wall_offset, 0, 100), wall_scale_y)

def build_cubicle(name_prefix, center_pos, size_x=2.0, size_y=2.0):
    """Genera un cubículo de oficina compuesto por escritorios y particiones"""
    cx, cy, cz = center_pos

    # Escritorio (Cubo estirado)
    spawn_mesh(name_prefix + "_Desk", CUBE_PATH, (cx, cy, cz + 30), (size_x, 1.0, 0.6))
    # Silla (Cilindro)
    spawn_mesh(name_prefix + "_Chair", CYLINDER_PATH, (cx, cy - 60, cz + 30), (0.4, 0.4, 0.6))
    # Partición/Pared corta del cubículo
    spawn_mesh(name_prefix + "_Divider", CUBE_PATH, (cx, cy + 80, cz + 75), (size_x + 0.5, 0.1, 1.5))

def setup_lighting_and_camera(camera_height=2400.0):
    """Crea la luz direccional, skylight y la camara cenital top-down"""
    log("Configurando iluminacion y camara cenital...")

    # Luz Direccional
    dir_light = unreal.EditorLevelLibrary.spawn_actor_from_class(
        unreal.DirectionalLight,
        unreal.Vector(0, 0, 1000),
        unreal.Rotator(-50, -30, 0)
    )
    if dir_light:
        dir_light.set_actor_label("Main_Office_Light")

    # SkyLight
    skylight = unreal.EditorLevelLibrary.spawn_actor_from_class(
        unreal.SkyLight,
        unreal.Vector(0, 0, 500),
        unreal.Rotator(0, 0, 0)
    )
    if skylight:
        skylight.set_actor_label("Office_SkyLight")

    # Camara Cenital Top-Down
    camera = unreal.EditorLevelLibrary.spawn_actor_from_class(
        unreal.CameraActor,
        unreal.Vector(0, 0, camera_height),
        unreal.Rotator(-90, 0, 0)
    )
    if camera:
        camera.set_actor_label("TopDown_MainCamera")
        cam_comp = camera.camera_component
        cam_comp.set_editor_property("current_focal_length", 20.0)
        cam_comp.set_editor_property("aspect_ratio", 16.0 / 9.0)
