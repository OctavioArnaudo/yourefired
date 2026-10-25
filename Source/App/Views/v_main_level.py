import unreal
import s_level
import c_environment

LEVEL_PATH = "/Game/YoureFired/Levels/Lvl_Main"
GM_PATH = "/Game/TopDown/Blueprints/MainLevelGM.MainLevelGM_C"

def build_main_level():
    s_level.initialize_level(LEVEL_PATH, GM_PATH)
    c_environment.spawn_ui_elements("Main")

    if unreal.EditorLevelLibrary.save_current_level():
        unreal.log("[MainLevelView] Lvl_Main generado/cargado con GM.")

if __name__ == "__main__":
    build_main_level()
