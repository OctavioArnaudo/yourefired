# ============================================================
# YOU'RE FIRED - View: Victory UI Level (Lvl_Victory) - MVC View
# ============================================================
import unreal
import level_builder_util as utils

LEVEL_PATH = "/Game/YoureFired/Levels/Lvl_Victory"

def build_victory_level():
    utils.open_or_create_level(LEVEL_PATH)
    utils.build_ui_level_elements("Victory")

    if unreal.EditorLevelLibrary.save_current_level():
        unreal.log("[VictoryLevelView] Lvl_Victory (UI Victory) generado/cargado correctamente.")

if __name__ == "__main__":
    build_victory_level()
