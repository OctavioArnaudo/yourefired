# ============================================================
# YOU'RE FIRED - Master View: Generate All Game Levels
# ============================================================
import unreal
import sys
import os

# Añadir el directorio actual al path de Python de Unreal para permitir importaciones relativas
script_dir = os.path.dirname(os.path.abspath(__file__))
if script_dir not in sys.path:
    sys.path.append(script_dir)

import main_level_view
import settings_level_view
import pilot_level_view
import victory_level_view
import defeat_level_view

def generate_all():
    unreal.log("[MasterView] Generando todos los niveles del juego (Main, Settings, Pilot, Victory, Defeat)...")
    try:
        main_level_view.build_main_level()
        settings_level_view.build_settings_level()
        pilot_level_view.build_pilot_level()
        victory_level_view.build_victory_level()
        defeat_level_view.build_defeat_level()
        unreal.log("[MasterView] ¡Todos los niveles generados exitosamente en /Game/YoureFired/Levels/!")
    except Exception as e:
        unreal.log_error("[MasterView] Error al generar niveles: " + str(e))

if __name__ == "__main__":
    generate_all()
