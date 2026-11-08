# ============================================================
# YOU'RE FIRED - Service : Damage Processing Service
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

class SDamageService:
    """Service: Servicio concentrador para aplicacion y procesamiento de dano."""

    def apply_damage(self, target_actor, amount):
        if not target_actor or not target_actor.is_valid():
            return False
        unreal.log(f"[SDamageService] Aplicando {amount} de dano a {target_actor.get_actor_label()}.")
        try:
            unreal.GameplayStatics.apply_damage(target_actor, float(amount), None, None, None)
            return True
        except Exception as e:
            unreal.log_warning(f"[SDamageService] Notificacion de dano controlado: {e}")
        return True
