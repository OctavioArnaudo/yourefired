# ============================================================
# YOU'RE FIRED - Master View: Generate All Game Levels
# ============================================================
import unreal
import sys
import os
import traceback

# Configurar sys.path para incluir todos los submódulos de Source/YoureFired/
current_dir = os.path.dirname(os.path.abspath(__file__))
yourefired_dir = os.path.dirname(current_dir) # Source/YoureFired

for subfolder in ['', 'Views', 'Controllers', 'Services', 'Models', 'Interfaces']:
    path = os.path.join(yourefired_dir, subfolder)
    if path not in sys.path:
        sys.path.insert(0, path)

import v_main_level
import v_settings_level
import v_pilot_level
import v_victory_level
import v_defeat_level

def generate_all():
    unreal.log("[MasterView] === INICIANDO GENERACION DE NIVELES ===")
    try:
        unreal.log("[MasterView] Construyendo Lvl_Main...")
        v_main_level.build_main_level()

        unreal.log("[MasterView] Construyendo Lvl_Settings...")
        v_settings_level.build_settings_level()

        unreal.log("[MasterView] Construyendo Lvl_Pilot (con Office layout)...")
        v_pilot_level.build_pilot_level()

        unreal.log("[MasterView] Construyendo Lvl_Victory...")
        v_victory_level.build_victory_level()

        unreal.log("[MasterView] Construyendo Lvl_Defeat...")
        v_defeat_level.build_defeat_level()

        unreal.log("[MasterView] === ¡TODOS LOS NIVELES GENERADOS CON EXITO! ===")
    except Exception as e:
        unreal.log_error("[MasterView] EXCEPCION DURANTE LA GENERACION: " + str(e))
        unreal.log_error(traceback.format_exc())

if __name__ == "__main__":
    generate_all()
