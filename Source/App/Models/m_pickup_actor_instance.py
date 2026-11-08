# ============================================================
# YOU'RE FIRED - Model : Pickup Actor Instance Data
# ============================================================
import sys
import os

_current_dir = os.path.dirname(os.path.abspath(__file__))
_app_dir = os.path.dirname(_current_dir) if os.path.basename(_current_dir) in ['Models', 'Controllers', 'Views', 'Services', 'Interfaces'] else _current_dir
for _folder in ['', 'Models', 'Controllers', 'Views', 'Services', 'Interfaces']:
    _path = os.path.join(_app_dir, _folder)
    if _path not in sys.path:
        sys.path.insert(0, _path)

import unreal

class MPickupActorInstanceData:
    """Model: Datos del pickup de vida (mini rombo)."""
    def __init__(self, heal_amount=25.0):
        self.heal_amount = float(heal_amount)
        self.b_is_collected = False
