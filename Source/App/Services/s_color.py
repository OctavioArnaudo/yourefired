# ============================================================
# YOU'RE FIRED - Service: Theme & Object Color Definitions
# ============================================================
import unreal

OBJECT_COLORS = {
    "Floor": unreal.LinearColor(0.2, 0.2, 0.22, 1.0),
    "Wall": unreal.LinearColor(0.75, 0.75, 0.73, 1.0),
    "Desk": unreal.LinearColor(0.45, 0.3, 0.15, 1.0),
    "Chair": unreal.LinearColor(0.12, 0.12, 0.12, 1.0),
    "Player": unreal.LinearColor(0.1, 0.5, 0.9, 1.0),
    "Coworker": unreal.LinearColor(0.9, 0.2, 0.2, 1.0),
    "Supervisor": unreal.LinearColor(0.95, 0.5, 0.05, 1.0),
    "Coffee": unreal.LinearColor(0.6, 0.35, 0.15, 1.0),
    "Signature": unreal.LinearColor(0.95, 0.85, 0.1, 1.0),
    "Door": unreal.LinearColor(0.1, 0.7, 0.6, 1.0),
    "UI": unreal.LinearColor(0.2, 0.6, 0.8, 1.0)
}

def get_color_for_name(name):
    """Service: Retorna un color LinearColor definido según el nombre o tipo de objeto."""
    for key, color in OBJECT_COLORS.items():
        if key in name:
            return color
    return unreal.LinearColor(0.5, 0.5, 0.5, 1.0)
