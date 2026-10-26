# ============================================================
# YOU'RE FIRED - Model: HUD UI State Data Model
# ============================================================
import unreal

class MWbpHudData:
    """Model: Representa los datos de estado para el HUD de usuario."""
    def __init__(self, stress_percent=0.0, coffee_percent=100.0, signatures_collected=0, total_signatures=5):
        self.stress_percent = min(100.0, max(0.0, stress_percent))
        self.coffee_percent = min(100.0, max(0.0, coffee_percent))
        self.signatures_collected = signatures_collected
        self.total_signatures = total_signatures
