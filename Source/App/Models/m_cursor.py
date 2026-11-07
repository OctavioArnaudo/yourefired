# ============================================================
# YOU'RE FIRED - Model : Cursor Targeting Data
# ============================================================
import unreal

class MCursorData:
    """Model: Posicion en mundo y direccion del cursor de apuntado."""

    def __init__(self):
        self.world_location = (0.0, 0.0, 0.0)
        self.world_direction = (1.0, 0.0, 0.0)
        self.b_is_target_valid = False

    def update_cursor_target(self, location, direction):
        self.world_location = location
        self.world_direction = direction
        self.b_is_target_valid = True
        unreal.log(f"[MCursorData] Destino del cursor actualizado: {location}")
