# ============================================================
# YOU'RE FIRED - Service : Pickup Actor Instance Service
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

class SPickupActorInstanceService:
    """Service: Servicio de generacion y administracion de pickups de salud rombo."""

    def spawn_health_pickup(self, location=(0.0, 0.0, 100.0)):
        unreal.log(f"[SPickupActorInstanceService] Generando pickup de salud rombo en {location}")
        return True
