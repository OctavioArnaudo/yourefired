# ============================================================
# YOU'RE FIRED - View : Pickup Actor Instance Visuals
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

class VPickupActorInstanceView:
    """View: Renderizado visual y efecto brillante del rombo de salud."""

    def render_pickup_glow(self, location):
        unreal.log(f"[VPickupActorInstanceView] Renderizando brillo de pickup rombo en {location}")
        return True
