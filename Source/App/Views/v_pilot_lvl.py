# ============================================================
# YOU'RE FIRED - View: Pilot Level (Master Wrapper for Office Level)
# ============================================================

import unreal
import s_level
import v_office_level

LEVEL_PATH = "/Game/YoureFired/Levels/Lvl_Pilot"
GM_PATH = "/Game/TopDown/Blueprints/PilotLevelGM.PilotLevelGM_C"

def build_pilot_level():
    unreal.log("[PilotLevelView] Inicializando nivel wrapper Lvl_Pilot...")

    # 1. Inicializar nivel y GameMode
    s_level.initialize_level(LEVEL_PATH, GM_PATH)

    # 2. Construir todo el contenido de la oficina dentro del nivel wrapper
    v_office_level.build_office_layout()

    # 3. Guardar el nivel completo
    if unreal.EditorLevelLibrary.save_current_level():
        unreal.log("[PilotLevelView] Lvl_Pilot (Wrapper) guardado exitosamente en: " + LEVEL_PATH)

if __name__ == "__main__":
    build_pilot_level()
