# ============================================================
# YOU'RE FIRED - View: Main Menu UI Level (Lvl_Main) - MVC View
# ============================================================
import unreal
import level_builder_util as utils

LEVEL_PATH = "/Game/YoureFired/Levels/Lvl_Main"

def build_main_level():
    utils.open_or_create_level(LEVEL_PATH)
    utils.build_ui_level_elements("Main")

    if unreal.EditorLevelLibrary.save_current_level():
        unreal.log("[MainLevelView] Lvl_Main (UI Menu) generado/cargado correctamente.")

if __name__ == "__main__":
    build_main_level()
