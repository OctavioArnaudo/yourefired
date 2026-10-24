# ============================================================
# YOU'RE FIRED - View: Settings UI Level (Lvl_Settings) - MVC View
# ============================================================
import unreal
import s_level
import c_environment

LEVEL_PATH = "/Game/YoureFired/Levels/Lvl_Settings"
GM_PATH = "/Game/TopDown/Blueprints/SettingsLevelGM.SettingsLevelGM_C"

def build_settings_level():
    s_level.initialize_level(LEVEL_PATH, GM_PATH)
    c_environment.spawn_ui_elements("Settings")

    if unreal.EditorLevelLibrary.save_current_level():
        unreal.log("[SettingsLevelView] Lvl_Settings (UI Settings) generado/cargado correctamente.")

if __name__ == "__main__":
    build_settings_level()
