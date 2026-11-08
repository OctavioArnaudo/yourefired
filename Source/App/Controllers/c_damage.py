# ============================================================
# YOU'RE FIRED - Controller : Damage Controller
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
from m_damage import MDamageData

class CDamageController:
    """Controller: Orquestador de calculos de dano y modificadores."""

    def __init__(self):
        self.damage_model = MDamageData()

    def handle_damage_event(self, raw_amount):
        dmg = self.damage_model.calculate_damage()
        unreal.log(f"[CDamageController] Evento de dano procesado: {dmg}")
        return dmg
