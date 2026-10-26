# ============================================================
# YOU'RE FIRED - Controller : Lvl
# ============================================================
import unreal
import c_actor_spawner

def handle_lvl_logic(location=(0,0,0)):
    """Controller: Lógica de control e interacción para Lvl."""
    unreal.log("[Controller:Lvl] Ejecutando lógica de control para Lvl.")
    return c_actor_spawner.spawn_actor("Lvl", "/Script/App.Lvl", location)
