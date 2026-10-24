import unreal
from .m_pickup import MPickupData

class MCoffeePickupData(MPickupData):
    """Model data for Coffee Pickup (reduces stress)."""
    def __init__(self, stress_relief=25.0):
        super().__init__()
        self.stress_relief = stress_relief
