# ============================================================
# YOU'RE FIRED - Model: Paper2D Flipbook Data Model
# ============================================================
import unreal

class MFBPlaceholderData:
    """Model: Representa los datos de animación 2D para Flipbooks."""
    def __init__(self, flipbook_name, frames_per_second=12.0, is_looping=True):
        self.flipbook_name = flipbook_name
        self.frames_per_second = frames_per_second
        self.is_looping = is_looping
        self.asset_path = f"/Game/YoureFired/Flipbooks/FB_{flipbook_name}.FB_{flipbook_name}"
