# ============================================================
# YOU'RE FIRED - View: World Levels Orchestrator
# ============================================================
import unreal
import v_main_level
import v_settings_level
import v_pilot_level
import v_victory_level
import v_defeat_level

def generate_all_levels():
    """View: Responsable exclusivo de coordinar la construcción de todos los niveles del juego."""
    unreal.log("[View:WorldLevels] === INICIANDO CONSTRUCCION DE NIVELES ===")

    v_main_level.build_main_level()
    v_settings_level.build_settings_level()
    v_pilot_level.build_pilot_level()
    v_victory_level.build_victory_level()
    v_defeat_level.build_defeat_level()

    unreal.log("[View:WorldLevels] === ¡TODOS LOS NIVELES CONSTRUIDOS EXITOSAMENTE! ===")
