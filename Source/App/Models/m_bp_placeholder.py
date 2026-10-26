# ============================================================
# YOU'RE FIRED - Model: Blueprint Player Configuration Data
# ============================================================
import unreal

OUTPUT_PATH = "/Game/YoureFired/Blueprints"
BLUEPRINT_NAME = "BP_Player"
FLIPBOOK_PATH = "/Game/YoureFired/Flipbooks/FB_Player_Idle"

WALK_SPEED = 300.0
CAMERA_ORTHO_WIDTH = 1200.0

class MBPPlaceholderData:
    """Model: Representa los metadatos y configuración de un Blueprint Placeholder."""
    def __init__(self, asset_name, package_path, parent_class_path):
        self.asset_name = asset_name
        self.package_path = package_path
        self.parent_class_path = parent_class_path

    def get_full_asset_path(self):
        return f"{self.package_path}/{self.asset_name}.{self.asset_name}"
