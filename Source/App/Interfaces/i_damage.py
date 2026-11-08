# ============================================================
# YOU'RE FIRED - Interface : Damage Contract
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

class IDamageInterface:
    """Interface: Contrato estricto para gestion de dano."""

    def receive_damage(self, amount):
        unreal.log(f"[IDamageInterface] Contrato receive_damage ejecutado con {amount} HP.")
        return float(amount)
