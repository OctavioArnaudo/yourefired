import unreal

class MDoorData:
    """Model data for Office Door."""
    def __init__(self, required_signatures=3):
        self.required_signatures = required_signatures
        self.is_unlocked = False
