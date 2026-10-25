import unreal

class MPickupData:
    """Model data for Pickup items."""
    def __init__(self, item_value=1.0):
        self.item_value = item_value
        self.b_is_collected = False
