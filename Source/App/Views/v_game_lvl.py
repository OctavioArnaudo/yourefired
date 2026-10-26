# ============================================================
# YOU'RE FIRED - View: Gameplay World Levels Layout Orchestrator
# ============================================================
import unreal
import v_pilot_lvl

def generate_game_levels():
    """View: Genera y construye exclusivamente los niveles jugables de acción (Lvl_Pilot y pisos de oficina)."""
    unreal.log("[View:GameLvl] Construyendo niveles jugables de acción...")
    v_pilot_lvl.build_pilot_level()
