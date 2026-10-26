# ============================================================
# YOU'RE FIRED - View: 2D Office Floor & Wall Perimeter
# ============================================================
import unreal
import c_sm_spawner as c_mesh_spawner

CUBE_PATH = "/Engine/BasicShapes/Cube.Cube"

def build_office_perimeter(wall_offset=1600.0):
    """View: Construye el perímetro y suelo en el plano 2D XY."""
    unreal.log("[View:OfficePerimeter] Construyendo suelo y paredes 2D XY de la oficina...")
    c_mesh_spawner.spawn_mesh("Floor_Main", CUBE_PATH, (0, 0, 0), (32.0, 32.0, 0.1))
    c_mesh_spawner.spawn_mesh("Wall_North", CUBE_PATH, (0, wall_offset, 0), (1.0, 32.0, 1.0))
    c_mesh_spawner.spawn_mesh("Wall_South", CUBE_PATH, (0, -wall_offset, 0), (1.0, 32.0, 1.0))
    c_mesh_spawner.spawn_mesh("Wall_East", CUBE_PATH, (wall_offset, 0, 0), (32.0, 1.0, 1.0))
    c_mesh_spawner.spawn_mesh("Wall_West", CUBE_PATH, (-wall_offset, 0, 0), (32.0, 1.0, 1.0))
