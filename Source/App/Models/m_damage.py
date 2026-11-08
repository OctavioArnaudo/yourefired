# ============================================================
# YOU'RE FIRED - Model : Damage Parameters
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

class MDamageData:
    """Model: Configuracion de dano base, criticos y mitigacion."""

    def __init__(self, base_damage=25.0, crit_multiplier=1.5):
        self.base_damage = float(base_damage)
        self.crit_multiplier = float(crit_multiplier)

    def calculate_damage(self, multiplier=1.0):
        final_dmg = self.base_damage * self.crit_multiplier * float(multiplier)
        unreal.log(f"[MDamageData] Dano calculado: {final_dmg}")
        return final_dmg
