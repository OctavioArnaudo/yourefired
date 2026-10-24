# ============================================================
# YOU'RE FIRED - Master View: Generate All Game Levels
# ============================================================
import unreal
import sys
import os

# Configurar sys.path para incluir todos los submódulos de Source/YoureFired/
current_dir = os.path.dirname(os.path.abspath(__file__))
yourefired_dir = os.path.dirname(current_dir) # Source/YoureFired

for subfolder in ['', 'Views', 'Controllers', 'Services', 'Models', 'Interfaces']:
    path = os.path.join(yourefired_dir, subfolder)
    if path not in sys.path:
        sys.path.append(path)

import v_main_level
import v_settings_level
import v_pilot_level
import v_victory_level
import v_defeat_level

def generate_all():
    unreal.log("[MasterView] Generando todos los niveles del juego (Main, Settings, Pilot Wrapper con Office, Victory, Defeat)...")
    try:
        v_main_level.build_main_level()
        v_settings_level.build_settings_level()
        v_pilot_level.build_pilot_level()
        v_victory_level.build_victory_level()
        v_defeat_level.build_defeat_level()
        unreal.log("[MasterView] ¡Todos los niveles generados y configurados exitosamente desde código!")
    except Exception as e:
        unreal.log_error("[MasterView] Error crítico al generar niveles: " + str(e))

if __name__ == "__main__":
    generate_all()
