# ============================================================
# YOU'RE FIRED - View: Settings UI Level (Lvl_Settings) - MVC View
# ============================================================
import unreal
import level_builder_util as utils

LEVEL_PATH = "/Game/YoureFired/Levels/Lvl_Settings"

def build_settings_level():
    utils.open_or_create_level(LEVEL_PATH)
    utils.build_ui_level_elements("Settings")

    if unreal.EditorLevelLibrary.save_current_level():
        unreal.log("[SettingsLevelView] Lvl_Settings (UI Settings) generado/cargado correctamente.")

if __name__ == "__main__":
    build_settings_level()
