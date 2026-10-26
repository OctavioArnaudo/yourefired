# ============================================================
# YOU'RE FIRED - Controller : DefeatLvl
# ============================================================
import unreal
import c_actor_spawner

def handle_defeat_lvl_logic(location=(0,0,0)):
    """Controller: Lógica de control e interacción para DefeatLvl."""
    unreal.log("[Controller:DefeatLvl] Ejecutando lógica de control para DefeatLvl.")
    return c_actor_spawner.spawn_actor("DefeatLvl", "/Script/App.DefeatLvl", location)
