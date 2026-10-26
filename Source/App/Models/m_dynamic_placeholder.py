# ============================================================
# YOU'RE FIRED - Model : DynamicPlaceholder
# ============================================================
import unreal

class MDynamicPlaceholderData:
    """Model: Definición de datos, parámetros y estado para DynamicPlaceholder."""
    def __init__(self, value=100.0, is_active=True):
        self.domain_name = "dynamic_placeholder"
        self.value = value
        self.is_active = is_active
        self.config_path = "/Game/YoureFired/Data/DT_DynamicPlaceholder"

    def get_summary(self):
        return f"DynamicPlaceholder State -> Active: {self.is_active}, Value: {self.value}"
