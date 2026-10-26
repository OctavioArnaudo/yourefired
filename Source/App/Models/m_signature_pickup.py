# ============================================================
# YOU'RE FIRED - Model : SignaturePickup
# ============================================================
import unreal

class MSignaturePickupData:
    """Model: Definición de datos, parámetros y estado para SignaturePickup."""
    def __init__(self, value=100.0, is_active=True):
        self.domain_name = "signature_pickup"
        self.value = value
        self.is_active = is_active
        self.config_path = "/Game/YoureFired/Data/DT_SignaturePickup"

    def get_summary(self):
        return f"SignaturePickup State -> Active: {self.is_active}, Value: {self.value}"
