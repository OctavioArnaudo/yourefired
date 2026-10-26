# ============================================================
# YOU'RE FIRED - Controller : VictoryLvl
# ============================================================
import unreal
import c_actor_spawner

def handle_victory_lvl_logic(location=(0,0,0)):
    """Controller: Lógica de control e interacción para VictoryLvl."""
    unreal.log("[Controller:VictoryLvl] Ejecutando lógica de control para VictoryLvl.")
    return c_actor_spawner.spawn_actor("VictoryLvl", "/Script/App.VictoryLvl", location)
