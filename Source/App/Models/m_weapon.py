import unreal

class MWeaponData:
    """Model data for Weapons."""
    def __init__(self, ammo=30, fire_rate=0.2):
        self.ammo = ammo
        self.max_ammo = ammo
        self.fire_rate = fire_rate
