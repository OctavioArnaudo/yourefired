import unreal

class MEnemyData:
    """Model data for Enemy entities."""
    def __init__(self, damage=10.0, speed=300.0):
        self.damage = damage
        self.speed = speed
        self.aggro_range = 500.0
