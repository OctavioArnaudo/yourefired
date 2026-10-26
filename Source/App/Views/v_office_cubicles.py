# ============================================================
# YOU'RE FIRED - View: Office Cubicles & Furniture Layout
# ============================================================
import unreal
import c_sm_spawner as c_mesh_spawner

CUBE_PATH = "/Engine/BasicShapes/Cube.Cube"
CYLINDER_PATH = "/Engine/BasicShapes/Cylinder.Cylinder"

def build_office_cubicles(positions=None):
    """View: Construye exclusivamente el mobiliario y cubículos de la oficina."""
    unreal.log("[View:OfficeCubicles] Construyendo cubículos y escritorios...")
    if positions is None:
        positions = [
            (-800, 600, 0),  (800, 600, 0),
            (-800, 0, 0),    (800, 0, 0),
            (-800, -600, 0), (800, -600, 0),
            (0, 400, 0),     (0, -400, 0)
        ]
    for idx, pos in enumerate(positions):
        cx, cy, cz = pos
        c_mesh_spawner.spawn_mesh(f"Cubicle_{idx+1:02d}_Desk", CUBE_PATH, (cx, cy, cz + 30), (2.0, 1.0, 0.6))
        c_mesh_spawner.spawn_mesh(f"Cubicle_{idx+1:02d}_Chair", CYLINDER_PATH, (cx, cy - 60, cz + 30), (0.4, 0.4, 0.6))
