# ============================================================
# YOU'RE FIRED - View: Master World Levels Orchestrator
# ============================================================
import unreal
import v_ui_lvl
import v_game_lvl

def generate_all_levels():
    """View: Orquestador maestro ultra-ligero que delega la generación a v_ui_lvl y v_game_lvl."""
    unreal.log("[View:WorldLevels] === INICIANDO CONSTRUCCION DE TODOS LOS NIVELES ===")
    v_ui_lvl.generate_ui_levels()
    v_game_lvl.generate_game_levels()
    unreal.log("[View:WorldLevels] === ¡TODOS LOS NIVELES CONSTRUIDOS EXITOSAMENTE! ===")
