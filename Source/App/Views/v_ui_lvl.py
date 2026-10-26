# ============================================================
# YOU'RE FIRED - View: UI Levels Layout Orchestrator
# ============================================================
import unreal
import v_main_lvl
import v_settings_lvl
import v_victory_lvl
import v_defeat_lvl

def generate_ui_levels():
    """View: Genera y construye exclusivamente los niveles de interfaz de usuario (Main, Settings, Victory, Defeat)."""
    unreal.log("[View:UiLvl] Construyendo niveles de interfaz de usuario...")
    v_main_lvl.build_main_level()
    v_settings_lvl.build_settings_level()
    v_victory_lvl.build_victory_level()
    v_defeat_lvl.build_defeat_level()
