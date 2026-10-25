# ============================================================
# YOU'RE FIRED - View: World Levels Orchestrator
# ============================================================
import unreal
import v_main_lvl
import v_settings_lvl
import v_pilot_lvl
import v_victory_lvl
import v_defeat_lvl

def generate_all_levels():
    """View: Responsable exclusivo de coordinar la construcción de todos los niveles del juego."""
    unreal.log("[View:WorldLevels] === INICIANDO CONSTRUCCION DE NIVELES ===")

    v_main_lvl.build_main_level()
    v_settings_lvl.build_settings_level()
    v_pilot_lvl.build_pilot_level()
    v_victory_lvl.build_victory_level()
    v_defeat_lvl.build_defeat_level()

    unreal.log("[View:WorldLevels] === ¡TODOS LOS NIVELES CONSTRUIDOS EXITOSAMENTE! ===")
