# ============================================================
# YOU'RE FIRED - Master View: Generate All Game Levels
# ============================================================
import unreal
import sys
import os

script_dir = os.path.dirname(os.path.abspath(__file__))
if script_dir not in sys.path:
    sys.path.append(script_dir)

import v_main_level
import v_settings_level
import v_pilot_level
import v_victory_level
import v_defeat_level
import v_office_level

def generate_all():
    unreal.log("[MasterView] Generando todos los niveles del juego (Main, Settings, Pilot, Victory, Defeat, Office)...")
    try:
        v_main_level.build_main_level()
        v_settings_level.build_settings_level()
        v_pilot_level.build_pilot_level()
        v_victory_level.build_victory_level()
        v_defeat_level.build_defeat_level()
        v_office_level.generate_office_level()
        unreal.log("[MasterView] ¡Todos los niveles generados y configurados exitosamente desde código!")
    except Exception as e:
        unreal.log_error("[MasterView] Error al generar niveles: " + str(e))

if __name__ == "__main__":
    generate_all()
