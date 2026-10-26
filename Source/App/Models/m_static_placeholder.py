# ============================================================
# YOU'RE FIRED - Model : StaticPlaceholder
# ============================================================
import unreal

class MStaticPlaceholderData:
    """Model: Definición de datos, parámetros y estado para StaticPlaceholder."""
    def __init__(self, value=100.0, is_active=True):
        self.domain_name = "static_placeholder"
        self.value = value
        self.is_active = is_active
        self.config_path = "/Game/YoureFired/Data/DT_StaticPlaceholder"

    def get_summary(self):
        return f"StaticPlaceholder State -> Active: {self.is_active}, Value: {self.value}"
