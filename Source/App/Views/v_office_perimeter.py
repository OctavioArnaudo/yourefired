# ============================================================
# YOU'RE FIRED - View: Office Floor & Wall Perimeter Layout
# ============================================================
import unreal
import c_sm_spawner as c_mesh_spawner

CUBE_PATH = "/Engine/BasicShapes/Cube.Cube"

def build_office_perimeter(wall_offset=1600.0):
    """View: Construye exclusivamente el perímetro, suelo y paredes de la oficina."""
    unreal.log("[View:OfficePerimeter] Construyendo suelo y perímetro de la oficina...")
    c_mesh_spawner.spawn_mesh("Floor_Main", CUBE_PATH, (0, 0, -50), (32.0, 32.0, 1.0))
    c_mesh_spawner.spawn_mesh("Wall_North", CUBE_PATH, (0, wall_offset, 100), (1.0, 32.0, 3.0))
    c_mesh_spawner.spawn_mesh("Wall_South", CUBE_PATH, (0, -wall_offset, 100), (1.0, 32.0, 3.0))
    c_mesh_spawner.spawn_mesh("Wall_East", CUBE_PATH, (wall_offset, 0, 100), (32.0, 1.0, 3.0))
    c_mesh_spawner.spawn_mesh("Wall_West", CUBE_PATH, (-wall_offset, 0, 100), (32.0, 1.0, 3.0))
