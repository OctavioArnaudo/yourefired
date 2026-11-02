# ============================================================
# YOU'RE FIRED - Model: Player Character Instance Data Model
# ============================================================
import unreal

class MPlayerCharacterInstanceData:
    """Model: Representa los datos de instancia activa del personaje del jugador."""
    def __init__(self, instance_id="Player_Main_01", spawn_location=(0, -1200, 0), health=100.0):
        self.instance_id = instance_id
        self.spawn_location = spawn_location
        self.health = health
        self.is_spawned = True
