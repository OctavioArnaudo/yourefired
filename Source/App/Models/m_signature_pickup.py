import unreal
from .m_pickup import MPickupData

class MSignaturePickupData(MPickupData):
    """Model data for Approval Signature Pickup."""
    def __init__(self):
        super().__init__()
        self.signature_name = "Approval Stamp"
