# ============================================================
# YOU'RE FIRED - Controller : PilotLvl
# ============================================================
import unreal
import c_actor_spawner

def handle_pilot_lvl_logic(location=(0,0,0)):
    """Controller: Lógica de control e interacción para PilotLvl."""
    unreal.log("[Controller:PilotLvl] Ejecutando lógica de control para PilotLvl.")
    return c_actor_spawner.spawn_actor("PilotLvl", "/Script/App.PilotLvl", location)
