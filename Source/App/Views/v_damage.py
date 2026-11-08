# ============================================================
# YOU'RE FIRED - View : Damage Visuals & Hit Numbers
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

class VDamageView:
    """View: Renderizado de textos flotantes de dano e indicadores de impacto."""

    def render_damage_popup(self, damage_amount, location):
        unreal.log(f"[VDamageView] Popup de dano: -{damage_amount} HP en posicion {location}")
        return True
