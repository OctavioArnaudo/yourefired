import unreal

class MOfficeGMData:
    """Model data for Office GameMode state."""
    def __init__(self, current_floor=1):
        self.current_floor = current_floor
        self.max_floors = 4
