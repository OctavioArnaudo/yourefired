# ============================================================
# YOU'RE FIRED - View: Victory UI Level (Lvl_Victory) - MVC View
# ============================================================
import unreal
import s_lvl
import c_environment

LEVEL_PATH = "/Game/YoureFired/Levels/Lvl_Victory"
GM_PATH = "/Game/TopDown/Blueprints/VictoryLevelGM.VictoryLevelGM_C"

def build_victory_level():
    s_lvl.initialize_level(LEVEL_PATH, GM_PATH)
    c_environment.spawn_ui_elements("Victory")

    if unreal.EditorLevelLibrary.save_current_level():
        unreal.log("[VictoryLevelView] Lvl_Victory (UI Victory) generado/cargado correctamente.")

if __name__ == "__main__":
    build_victory_level()
