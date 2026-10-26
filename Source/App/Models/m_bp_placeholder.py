# ============================================================
# YOU'RE FIRED - Model: Blueprint Placeholder Data Model
# ============================================================
import unreal

class MBPPlaceholderData:
    """Model: Representa los metadatos y configuración de un Blueprint Placeholder."""
    def __init__(self, asset_name, package_path, parent_class_path):
        self.asset_name = asset_name
        self.package_path = package_path
        self.parent_class_path = parent_class_path

    def get_full_asset_path(self):
        return f"{self.package_path}/{self.asset_name}.{self.asset_name}"
