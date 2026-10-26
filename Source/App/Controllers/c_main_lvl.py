# ============================================================
# YOU'RE FIRED - Controller : MainLvl
# ============================================================
import unreal
import c_actor_spawner

def handle_main_lvl_logic(location=(0,0,0)):
    """Controller: Lógica de control e interacción para MainLvl."""
    unreal.log("[Controller:MainLvl] Ejecutando lógica de control para MainLvl.")
    return c_actor_spawner.spawn_actor("MainLvl", "/Script/App.MainLvl", location)
