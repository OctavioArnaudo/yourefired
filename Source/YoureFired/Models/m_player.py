import unreal

class MPlayerData:
    """Model data for Player stats."""
    def __init__(self, max_health=100.0, max_stress=100.0):
        self.max_health = max_health
        self.max_stress = max_stress
        self.current_health = max_health
        self.current_stress = 0.0
