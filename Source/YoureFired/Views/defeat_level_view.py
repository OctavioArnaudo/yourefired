# ============================================================
# YOU'RE FIRED - View: Defeat UI Level (Lvl_Defeat) - MVC View
# ============================================================
import unreal
import level_builder_util as utils

LEVEL_PATH = "/Game/YoureFired/Levels/Lvl_Defeat"

def build_defeat_level():
    utils.open_or_create_level(LEVEL_PATH)
    utils.build_ui_level_elements("Defeat")

    if unreal.EditorLevelLibrary.save_current_level():
        unreal.log("[DefeatLevelView] Lvl_Defeat (UI Defeat / You're Fired) generado/cargado correctamente.")

if __name__ == "__main__":
    build_defeat_level()
