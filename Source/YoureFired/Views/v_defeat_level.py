# ============================================================
# YOU'RE FIRED - View: Defeat UI Level (Lvl_Defeat) - MVC View
# ============================================================
import unreal
from Builders import s_level, c_environment

LEVEL_PATH = "/Game/YoureFired/Levels/Lvl_Defeat"
GM_PATH = "/Game/TopDown/Blueprints/DefeatLevelGM.DefeatLevelGM_C"

def build_defeat_level():
    s_level.initialize_level(LEVEL_PATH, GM_PATH)
    c_environment.spawn_ui_elements("Defeat")

    if unreal.EditorLevelLibrary.save_current_level():
        unreal.log("[DefeatLevelView] Lvl_Defeat (UI Defeat / You're Fired) generado/cargado correctamente.")

if __name__ == "__main__":
    build_defeat_level()
